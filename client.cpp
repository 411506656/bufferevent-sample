#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h> 
#include <net/if.h> 
#include <sys/ioctl.h>
#include <pthread.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/util.h>
    

#include "mirroring.pb.h"



using namespace std;


#define MAC_SIZE    18
#define IP_SIZE     16
static const char MESSAGE[] = "Hello, World!\n";
static const unsigned int PORT = 8899;

char ip[IP_SIZE] = "\0";  
char mac[MAC_SIZE] = "\0";
bool streammode = false;
bool isstart = false;
const char *local_eth = "eno1";

event_base *base;


static void reconnect_cb(evutil_socket_t s, short what, void *arg);    
static void server_msg_cb(bufferevent *bev, void *arg);
static void event_cb(bufferevent *bev, short event, void *arg);
static void signal_cb(evutil_socket_t, short, void *);
static int get_local_mac(const char *eth_inf, char *mac); // 获取本机mac  
static int get_local_ip(const char *eth_inf, char *ip); // 获取本机ip
static int strtok_section(char *pSrc);
static int bufferevent_socket_connect_retry();
static int search_server_addr();
static int ping_socket(char* ip_addr);



int main(int argc, char **argv) {

    int ret = -1;
    struct timeval tv;
    struct event *signal_event;

    pthread_t control_mirroring_thread;


    do {
        ret = search_server_addr();
        usleep(1000*1000);
    } while (ret != 0);


    base = event_base_new();
    bufferevent *bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE | BEV_OPT_DEFER_CALLBACKS);
    // signal_event = evsignal_new(base, SIGINT, signal_cb, (void *)base);

    // if (!signal_event || event_add(signal_event, NULL)<0) {
    //     fprintf(stderr, "Could not create/add a signal event!\n");
    //     return 1;
    // }


    // event* ev_time = event_new(base, -1, EV_TIMEOUT, reconnect_cb, (void *)bev);
    // event_add(ev_time, &tv);

    sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);  

    ret = bufferevent_socket_connect(bev, (sockaddr *)&server_addr, sizeof(server_addr));
    printf(">>>>>>>>>>>>>>>>>>>>>ret :%d\n", ret);

    bufferevent_setcb(bev, server_msg_cb, NULL, event_cb, (void *)bev);
    bufferevent_disable(bev, EV_READ|EV_WRITE);

    // tv = {0, 100*1000};
    // bufferevent_set_timeouts(bev, &tv, NULL);


    event_base_dispatch(base);

    printf("Finished\n");
    return 0;
}



void *
start_usb_mirroring() {

}


static int 
send_message(bufferevent *bev, short event, void *arg) {
    int ret = 0;
    char rtsp_url[128] = "\0";

    printf("Client has successfully cliented.\n");

    snprintf(rtsp_url, sizeof(rtsp_url), "rtsp://%s:7554/live", ip);


    // rbs::MirroringReport report;
    // report.set_devicetype(1);
    // report.set_isstreamready(false);
    // report.set_rtspserverurl(rtsp_url);
    // report.set_localmac(mac);

    // auto newreport = new rbs::MirroringReport(report);

    // rbs::MirroringRequest request;
    // request.set_id(1);
    // request.set_allocated_report(newreport);

    // const size_t size = (size_t)request.ByteSize();
    // char sendbuf[size];
    // if(!request.SerializeToArray(sendbuf, (int)size)) {
    //     printf("serialize request error !\n");
    // }

    // //printf("send message: %s\n", sendbuf);
    // bufferevent_enable(bev, EV_READ | EV_PERSIST | EV_WRITE);
    // ret = bufferevent_write(bev, sendbuf, (int)size);
    
    bufferevent_enable(bev, EV_READ | EV_PERSIST | EV_WRITE);
    ret = bufferevent_write(bev, MESSAGE, sizeof(MESSAGE));
    printf("bufferevent_write>>>>>>>>ret: %d\n", ret);

    return ret;
}



static int 
bufferevent_socket_connect_retry() {
    int ret = 0;

    do {
        ret = search_server_addr();
        usleep(1000*1000);
    } while (ret != 0);

    bufferevent *bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE | BEV_OPT_DEFER_CALLBACKS);
    sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    ret = bufferevent_socket_connect(bev, (sockaddr *)&server_addr, sizeof(server_addr));
    printf(">>>>>>>>>>>>>>>>>>>>>bufferevent_socket_connect_retry ret :%d\n", ret);

    bufferevent_setcb(bev, server_msg_cb, NULL, event_cb, (void *)bev);
    bufferevent_disable(bev, EV_READ | EV_WRITE);

    // struct timeval tv;
    // tv = {0, 100*1000};
    // bufferevent_set_timeouts(bev, &tv, NULL);

    return ret;
}


static int 
strtok_section(char *pSrc) {  
    

    if (!pSrc) {
        printf("strtok_section error\n");
        return -1;
    }

    int ip_cut_length = 0;
    char *pToken = NULL; 
    char *pToken_before = NULL; 
    char *pDelimiter = (char *)".";  
    pToken = strtok(pSrc, pDelimiter);  

    printf("Strtok Begin:\n");   
    while (pToken) {  
        printf("pToken:%s\n", pToken); 
        printf("len:%d\n", (int)strlen(pToken));
        ip_cut_length = (int)strlen(pToken);
        pToken = strtok(NULL, pDelimiter);  
    } 
    printf("Strtok End!\n");  

    return ip_cut_length;
}


static void
reconnect_cb(evutil_socket_t s, short what, void *arg) {

    printf("________reconnect_cb\n");
}


static void 
server_msg_cb(bufferevent *bev, void *arg) {
    char msg[1024];

    size_t len = bufferevent_read(bev, msg, sizeof(msg)-1);
    
    //printf("Recv %s from server.\n", msg);

    // rbs::MirroringReplay replay;
    // replay.ParseFromArray(msg, len);

    // int id = replay.id();
    // if (!replay.has_switchon()) {
    //     printf("has_switch NULL!!!\n");
    //     return;
    // }

    // rbs::MirrorSwitch switchon;
    // switchon = replay.switchon();
    // uint64_t timestamp = switchon.timestamp();
    // bool isbreak = switchon.isbreak();
    // printf("id: %d timestamp: %llu isbreak: %d\n", id, timestamp, isbreak);

    //msg[len] = '\0';

    printf("Recv %s from server.\n", msg);
}


static void 
event_cb(bufferevent *bev, short event, void *arg) {
    int ret = -1;
    if (event & BEV_EVENT_EOF) {
        printf("Connection closed.\n");
    }
    else if (event & BEV_EVENT_ERROR) {
        printf("Got an error on the connection: %s\n",
            strerror(errno));/**/
    }
    else if (event & BEV_EVENT_CONNECTED) {
        send_message(bev, event, arg);
        // printf("Client has successfully cliented.\n");
        // bufferevent_enable(bev, EV_READ | EV_PERSIST | EV_WRITE);
        // ret = bufferevent_write(bev, MESSAGE, strlen(MESSAGE));
        // printf("bufferevent_write>>>>>>>>ret: %d\n", ret);
        return;
    }
    else if (event & BEV_EVENT_TIMEOUT) {
        printf("connection timeout: %s\n",
            strerror(errno));/**/
    }
    else {
        printf("Got an other error on the connection: %s\n",
            strerror(errno));/**/
    }
    bufferevent_free(bev);

    //reconnect server
    bufferevent_socket_connect_retry();  
}



static void
signal_cb(evutil_socket_t sig, short events, void *user_data) {
    struct event_base *base = (event_base *)user_data;
    struct timeval delay = { 2, 0 };

    printf("Caught an interrupt signal; exiting cleanly in two seconds.\n");

    event_base_loopexit(base, &delay);
}

 
static int 
get_local_mac(const char *eth_inf, char *mac) {  
    struct ifreq ifr;  
    int sd;  
      
    bzero(&ifr, sizeof(struct ifreq));  
    if( (sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)  
    {  
        printf("get %s mac address socket creat error\n", eth_inf);  
        return -1;  
    }  
      
    strncpy(ifr.ifr_name, eth_inf, sizeof(ifr.ifr_name) - 1);  
  
    if(ioctl(sd, SIOCGIFHWADDR, &ifr) < 0)  
    {  
        printf("get %s mac address error\n", eth_inf);  
        close(sd);  
        return -1;  
    }  
  
    snprintf(mac, MAC_SIZE, "%02x:%02x:%02x:%02x:%02x:%02x",  
        (unsigned char)ifr.ifr_hwaddr.sa_data[0],   
        (unsigned char)ifr.ifr_hwaddr.sa_data[1],  
        (unsigned char)ifr.ifr_hwaddr.sa_data[2],   
        (unsigned char)ifr.ifr_hwaddr.sa_data[3],  
        (unsigned char)ifr.ifr_hwaddr.sa_data[4],  
        (unsigned char)ifr.ifr_hwaddr.sa_data[5]);  
  
    close(sd);  
      
    return 0;  
}  
  
  
  
static int 
get_local_ip(const char *eth_inf, char *ip) {  
    int sd;  
    struct sockaddr_in sin;  
    struct ifreq ifr;  
  
    sd = socket(AF_INET, SOCK_DGRAM, 0);  
    if (-1 == sd)  
    {  
        printf("socket error: %s\n", strerror(errno));  
        return -1;        
    }  
  
    strncpy(ifr.ifr_name, eth_inf, IFNAMSIZ);  
    ifr.ifr_name[IFNAMSIZ - 1] = 0;  
      
  
    if (ioctl(sd, SIOCGIFADDR, &ifr) < 0)  
    {  
        printf("ioctl error: %s\n", strerror(errno));  
        close(sd);  
        return -1;  
    }  
  
    memcpy(&sin, &ifr.ifr_addr, sizeof(sin));  
    snprintf(ip, IP_SIZE, "%s", inet_ntoa(sin.sin_addr));  
  
    close(sd);  
    return 0;  
}

static int
ping_socket(char* ip_addr) { 
    int socket_descriptor;  
    struct sockaddr_in pin;  

    bzero(&pin,sizeof(pin));  
    pin.sin_family = AF_INET;  
    inet_pton(AF_INET, ip_addr, &pin.sin_addr);  
    pin.sin_port = htons(PORT);  
 
    if ((socket_descriptor = socket(AF_INET,SOCK_STREAM,0)) == -1) {  
        perror("error opening socket \n");  
        return -1;  
    }  

    if (connect(socket_descriptor,(struct sockaddr * )&pin, sizeof(pin)) == -1) {  
        perror("error connecting to socket \n");  
        close(socket_descriptor);
        return -1;  
    } 
    else {
        printf("connect successfully. tcp server address: %s\n", ip_addr);
    } 

    if (socket_descriptor) {
        close(socket_descriptor); 
    }
     
    return 0; 
}

static int
search_server_addr() {
    int result = 0;
    int ip_end = 2;
    int ip_cut_length = 0;

    char ip_cut[IP_SIZE] = "\0";
    char ip_joint[IP_SIZE] = "\0";
    char ip_buf[IP_SIZE] = "\0";


    result = get_local_mac(local_eth, mac);  
    if (0 != result) {
        goto RET_ERROR;
    }
    printf("local %s mac: %s\n", local_eth, mac);  
  
    result = get_local_ip(local_eth, ip);  
    if (0 != result) {
        goto RET_ERROR;
    }
    printf("local %s ip: %s\n", local_eth, ip);

    memcpy(ip_buf, ip, sizeof(ip));
    ip_cut_length = strtok_section(ip_buf);
    if (ip_cut_length <= 0) {
        result = ip_cut_length;
        goto RET_ERROR;
    }

    memset(ip_buf, 0, sizeof(ip_buf));
    memcpy(ip_buf, ip, strlen(ip) - ip_cut_length);

    
    while (true) {
        if (ip_end == 255) {
            ip_end = 2;
        }
        memset(ip_joint, 0, sizeof(ip_joint));
        snprintf(ip_joint, sizeof(ip_joint), "%s%d", ip_buf, ip_end++);
        result = ping_socket(ip_joint);
        if (0 == result) {
            break;
        }
    }

RET_ERROR:
    return result;

}


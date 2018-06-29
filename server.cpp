#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/thread.h>



#include "mirroring.pb.h"

static const unsigned int PORT = 8899;


using namespace std;

void listener_cb(evconnlistener *listener, evutil_socket_t fd,
         sockaddr *sock, int socklen, void *arg);

void socket_read_cb(bufferevent *bev, void *arg);

void socket_event_cb(bufferevent *bev, short events, void *arg);
static unsigned long long nanoTime(void);

int main(int argc, char **argv) {

    sockaddr_in sin;
    memset(&sin, 0, sizeof(sockaddr_in));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);

    event_base *base = event_base_new();
    evconnlistener *listener
        = evconnlistener_new_bind(base,
                      listener_cb, base,
                      LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE,
                      -1, (sockaddr*)&sin, sizeof(sockaddr_in));

    event_base_dispatch(base);

    evconnlistener_free(listener);
    event_base_free(base);

}

void listener_cb(evconnlistener *listener, evutil_socket_t fd,
        sockaddr *sock, int socklen, void *arg) {

    printf("accept a client %d\n", fd);
    event_base *base = (event_base *) arg;

    bufferevent *bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);

    bufferevent_setcb(bev, socket_read_cb, NULL, socket_event_cb, NULL);
    bufferevent_enable(bev, EV_READ | EV_PERSIST);

}


void socket_read_cb(bufferevent *bev, void *arg) {
    char msg[4096];
    size_t len = bufferevent_read(bev, msg, sizeof(msg) - 1);

    // //
    // rbs::MirroringRequest request;
    // request.ParseFromArray(msg, len);
    
    // int id = request.id();
    // if (!request.has_report()) {
    //     printf("has_report NULL!!!!!\n");
    //     return;
    // }

    // rbs::MirroringReport report;
    // report = request.report();
    // int devicetype = report.devicetype();
    // bool isstreamready = report.isstreamready();
    // string rtspserverurl = report.rtspserverurl();
    // string localmac = report.localmac();

    // printf("id: %d devicetype: %d isstreamready: %d rtspserverurl: %s localmac: %s\n", 
    //     id, devicetype, isstreamready, rtspserverurl.c_str(), localmac.c_str());

    // //
    // uint64_t timestamp = nanoTime();
    // printf("timestamp: %llu\n", timestamp);

    // rbs::MirrorSwitch switchon;
    // switchon.set_timestamp(timestamp);
    // switchon.set_isbreak(false);

    // auto newswitchon = new rbs::MirrorSwitch(switchon);
    // rbs::MirroringReplay replay;
    // replay.set_id(1);
    // replay.set_allocated_switchon(newswitchon);

    // const size_t size = (size_t)replay.ByteSize();
    // char sendbuf[size];
    // if(!replay.SerializeToArray(sendbuf, (int)size)) {
    //     printf("serialize replay error !\n");
    // }

    // bufferevent_write(bev, sendbuf, (int)size);


    //msg[len] = '\0';
    printf("Server read the data: %s\n", msg);

    char reply[] = "I have read your data.";
    bufferevent_write(bev, reply, sizeof(reply));
}

void socket_event_cb(bufferevent *bev, short events, void *arg) {
    if (events & BEV_EVENT_EOF) {
        printf("connection closed\n");
    }
    else if (events & BEV_EVENT_ERROR) {
        printf("connection error: %s\n",
            strerror(errno));
    }
    else if (events & BEV_EVENT_CONNECTED){
        printf("connection successfully\n");
        return;
    }
    else {
        printf("connection other error: %s\n",
            strerror(errno));
    }

    bufferevent_free(bev);
}


static unsigned long long nanoTime(void)
{
    struct timespec t;

    t.tv_sec = t.tv_nsec = 0;
    clock_gettime(CLOCK_MONOTONIC, &t);

    return (unsigned long long)(t.tv_sec) * 1000000000 + t.tv_nsec;
}

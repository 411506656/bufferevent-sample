rm -rf client server

g++ -std=c++11 -o server server.cpp -I/home/wuli/work/ndk_develop/libevent/include -L/home/wuli/work/ndk_develop/libevent/.libs/ -levent -lpthread \
-I/home/wuli/work/ndk_develop/bufferevent/ptotosrc/build \
-L/home/wuli/work/ndk_develop/bufferevent/ptotosrc/build -lprotocols_static \
-L/usr/lib/ -lprotobuf -ltcmalloc

g++ -std=c++11 -o client client.cpp -I/home/wuli/work/ndk_develop/libevent/include -L/home/wuli/work/ndk_develop/libevent/.libs/ -levent -lpthread \
-I/home/wuli/work/ndk_develop/bufferevent/ptotosrc/build \
-L/home/wuli/work/ndk_develop/bufferevent/ptotosrc/build -lprotocols_static  \
-L/usr/lib/ -lprotobuf -ltcmalloc

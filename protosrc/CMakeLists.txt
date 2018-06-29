
find_package(Protobuf REQUIRED)

PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEAD
        mirroring.proto
        )

include_directories(${PROTOBUF_INCLUDE_DIRS})
add_library(protocols_static STATIC ${PROTO_SRC} ${PROTO_HEAD})

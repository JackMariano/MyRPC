#aux_source_directory(. SRC_LIST)

set(SRC_LIST 
    myrpcapplication.cc 
    myrpcconfig.cc 
    rpcheader.pb.cc 
    rpcprovider.cc 
    myrpcchannel.cc
    myrpccontroller.cc
    logger.cc
    zookeeperutil.cc)
add_library(myrpc ${SRC_LIST})#添加库文件

# 为myrpc设置依赖，需要注意muduo库的连接顺序
target_link_libraries(myrpc muduo_net muduo_base pthread zookeeper_mt)
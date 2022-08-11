#pragma once

#include<semaphore.h>
#include<zookeeper/zookeeper.h>
#include<string>

//封装的zk客户端类
class ZkClient
{
public:
    //构造函数，析构函数
    ZkClient();
    ~ZkClient();
    //zkclinet启动链接zkserver
    void Start();
    //在zkserver上根据指定的path创建znode节点
    //path 路径，data数据，datalen数据长度， state 0 临时节点， 1 永久节点
    void Create(const char *path,const char *data,int datalen,int state=0);
    //传入参数指定的znode节点路径，获取znode节点的值
    std::string GetData(const char *path);

private:
    //zk的客户端句柄，通过这个句柄操作zkserver
    zhandle_t *m_zhandle;
};
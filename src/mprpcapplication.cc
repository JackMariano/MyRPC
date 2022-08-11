#include"myrpcapplication.h"
#include<iostream>
#include<unistd.h>
#include<string>

//静态成员变量在类外初始化
myrpcConfig myrpcApplication::m_config;
//实现成全局的方法
void ShowArgHelp()
{
    std::cout<<"format:command -i <configfile>"<<std::endl;
}
void myrpcApplication::Init(int argc,char **argv)//myrpc初始化
{
    if(argc<2)//参数不足
    {
        ShowArgHelp();//打印参数的配置说明
        exit(EXIT_FAILURE);
    }

    //使用getopt读取参数
    int c=0;
    std::string config_file;//配置选项
    while((c=getopt(argc,argv,"i:"))!=-1)//通过argc与argv获取参数，应该使用-i
    {
        switch (c)
        {
        case 'i'://指定选项，正常情况
            config_file=optarg;
            break;
        case '?'://出现了不想要的参数
            std::cout<<"invalid args"<<std::endl;
            ShowArgHelp();
            exit(EXIT_FAILURE);
        case ':'://出现了-i 但是没有带参数
            std::cout<<"need <configfile>"<<std::endl;
            ShowArgHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }
    //开始加载配置文件 加载IP，端口，zk的IP和端口
    m_config.LoadConfigFile(config_file.c_str());//转换为*char格式
    // std::cout<<"rpcserverip:"<<m_config.Load("rpcserverip")<<std::endl;
    // std::cout<<"rpcserverport:"<<m_config.Load("rpcserverport")<<std::endl;
    // std::cout<<"zookeeperip:"<<m_config.Load("zookeeperip")<<std::endl;
    // std::cout<<"zookeeperport:"<<m_config.Load("zookeeperport")<<std::endl;
}
//单例模式获取实例
myrpcApplication& myrpcApplication::GetInstance()
{
    static myrpcApplication app;
    return app;
}

//获取配置项
myrpcConfig& myrpcApplication::GetConfig()
{
    return m_config;
}
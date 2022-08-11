#include"myrpccontroller.h"

//类的构造函数
myrpcController::myrpcController()
{
    m_failed=false;
    m_errtext="";
}

void myrpcController::Reset()
{
    m_failed=false;
    m_errtext="";
}

bool myrpcController::Failed()const
{
    return m_failed;
}

std::string myrpcController::ErrorText()const
{
    return m_errtext;
}

void myrpcController::SetFailed(const std::string& reason)
{
    m_failed=true;
    m_errtext=reason;
}

void myrpcController::StartCancel(){}
bool myrpcController::IsCanceled()const{return false;}
void myrpcController::NotifyOnCancel(google::protobuf::Closure *callback){}
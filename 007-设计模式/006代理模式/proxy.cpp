/*
代理模式：当无法直接访问某个对象或访问某个对象存在困难时可以通过一个代理对象来间接访问，
为了保证客户端使用的透明性，所访问的真实对象与代理对象需要实现相同的接口。
根据代理模式的使用目的不同，代理模式又可以分为多种类型，例如保护代理、远程代理、虚拟代理、缓冲代理
等，它们应用于不同的场合，满足用户的不同需求。
*/

/*  某软件公司承接了某信息咨询公司的收费商务信息查询系统的开发任务，该系统的基本需求如下：
(1) 在进行商务信息查询之前用户需要通过身份验证，只有合法用户才能够使用该查询系统；
(2) 在进行商务信息查询时系统需要记录查询日志，以便根据查询次数收取查询费用。
该软件公司开发人员已完成了商务信息查询模块的开发任务，现希望能够以一种松耦合的方
式向原有系统增加身份验证和日志记录功能，客户端代码可以无区别地对待原始的商务信息
查询模块和增加新功能之后的商务信息查询模块，而且可能在将来还要在该信息查询模块中
增加一些新的功能。试使用代理模式设计并实现该收费商务信息查询系统
*/
#include<iostream>
#include<string>
using namespace std;

class AccessValidator;
class Logger;

class ISearcher{
    public:
    ISearcher();
    ISearcher(ISearcher* s){};//有参构造，给代理类使用
    virtual void search()=0;
};

class ProxySearcher:public ISearcher{
    public:
    ProxySearcher(ISearcher* s):ISearcher(s){
        realSearcher = s;
    }
    virtual void search(){
        cout<<"代理功能开始执行搜索功能···"<<endl;
        realSearcher->search();
        cout<<"RealSearcher执行搜索完毕"<<endl;
    }
    private:
    AccessValidator Validator;
    Logger logger;
    ISearcher* realSearcher;
};

class RealSearcher:public ISearcher{
    public:
    virtual void search(){
        cout<<"RealSearcher在进行搜索···"<<endl;
    }
};

class AccessValidator{
    public:
    bool validate(string userInfo){
        cout<<"验证用户身份通过···"<<endl;
    }
};

class Logger{
    public:
    void log(string userInfo){
        cout<<"用户"<<userInfo<<"进行了搜索"<<endl;
    }
};

//------------------------------------------------------------------
//快捷方式(软连接)的例子
class IFile{
    public:
    IFile(){}
    IFile(IFile *file){};
    virtual void exec()=0;
};
class RealFile : public IFile{
    public:
    virtual void exec(){
        cout<<fullPath<<"开始执行···"<<endl;
    }
    private:
    string fullPath;
};

class ShortCut :public IFile{
    public:
    ShortCut(IFile* file){
        this->file = file;
    }
    virtual void exec(){
        file->exec();
    } 
    private:
    IFile* file;
};
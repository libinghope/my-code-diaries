/*
原型模式相对来说比较简单,就是通过一个对象来构造另外一个对象
java中的cloneable接口就是原型模式

假设某个公司的员工每周都需要提交一份周报，但是同一岗位的工作内容基本是一致的
开发人员决定使用原型模式来实现工作周报的快速创建
*/
#include<string>
using namespace std;
class Object{
    virtual Object* clone()=0;
};

class WeeklyLog :public Object{
    public:
    virtual WeeklyLog* clone(){
        WeeklyLog *log = new WeeklyLog;
        log->content = content;
        return log;
    }
    private:
    string content;
};

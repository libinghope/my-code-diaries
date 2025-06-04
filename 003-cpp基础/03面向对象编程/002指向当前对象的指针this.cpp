/*
C++中，类的成员变量和成员函数是分开存储的，也就是说多个对象共同调用同意一份函数代码，
那么，如何确定究竟是哪个对象在调用当前函数呢？
C++提供了成员函数中默认的this指针——指向当前对象本身。
*/
class ClassA{
    public:
    ClassA(){ this->m_a=10;}//编译器会帮我们做处理，处理过后变成如下这个样子
    //ClassA(ClassA * this){}//这里的this就是构造出来的对象的首地址(指针)

    void function1(int a){this->m_a=a;}//经过编译器处理变成了如下
    //void function1(ClassA * this, int a){this->m_a=a;}

    //静态成员函数里面没有this指针,静态成员函数不能操作成员变量
    static void function2(){}

    private:
    int m_a;
};
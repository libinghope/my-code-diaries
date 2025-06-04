//父类类模板
template<class T>
class Base
{
	T m;
};

//派生出模板类
template<class T >
class Child2 : public Base<double>  //继承类模板的时候，必须要确定基类的大小
{
public:
	T mParam;
};

void test02()
{
	Child2<int> d2;
}

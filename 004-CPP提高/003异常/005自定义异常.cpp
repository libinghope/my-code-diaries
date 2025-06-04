#include<iostream>
#include<string>
using namespace std;

//自定义异常类通常都会从C++标准库中的异常类派生
class MyOutOfRange:public exception
{
public:
	MyOutOfRange(const string  errorInfo)
	{
		this->m_Error = errorInfo;
	}

	MyOutOfRange(const char * errorInfo)
	{
		this->m_Error = string( errorInfo);
	}

	virtual  ~MyOutOfRange()
	{
	
	}
    /*在MAC上报错
	virtual const char *  what() const
	{
		return this->m_Error.c_str() ;
	}
    */

	string m_Error;

};

class Person
{
public:
	Person(int age)
	{
		if (age <= 0 || age > 150)
		{
			//抛出异常 越界
			//cout << "越界" << endl;
			//throw  out_of_range("年龄必须在0~150之间");

			//throw length_error("长度异常");
			throw MyOutOfRange(("我的异常 年龄必须在0~150之间"));
		}
		else
		{
			this->m_Age = age;
		}
		
	}

	int m_Age;
};


void test01()
{
	try
	{
		Person p(151);
	}
	catch ( out_of_range & e )
	{
		cout << e.what() << endl;
	}
	catch (length_error & e)
	{
		cout << e.what() << endl;
	}
	catch (MyOutOfRange e)
	{
		cout << e.what() << endl;
	}
}

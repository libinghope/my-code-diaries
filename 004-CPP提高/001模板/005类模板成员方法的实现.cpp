#include<iostream>
using namespace std;

template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
    //可以在类里面实现
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
    void showPerson1();
public:
	NameType mName;
	AgeType mAge;
};

//类方法在类外实现
template<class NameType, class AgeType>
void Person<NameType,AgeType>::showPerson1(){
    cout << "name: " << this->mName << " age: " << this->mAge << endl;
}

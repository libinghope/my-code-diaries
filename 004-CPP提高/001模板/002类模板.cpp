#include<iostream>
#include<string>
using namespace std;

//当类长成一个样子，只是参数类型不同，就可以使用类模板
template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

void test01()
{
	//Person P1("德玛西亚",18); // 类模板不能进行类型自动推导 
	Person<string, int>P1("德玛西亚", 18);
	P1.showPerson();
}

//类模板做函数参数
void DoBussiness(Person<string,int>& p){
	p.mAge += 20;
	p.mName += "_vip";
	p.showPerson();
}

int main(){

    return 0;
}

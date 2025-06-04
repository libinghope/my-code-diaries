#include<iostream>
using namespace std;

//父类引用或指针可以指向子类对象，通过父类指针或引用来操作子类对象。
class Animal{
public:
	void speak(){
		cout << "动物在唱歌..." << endl;
	}
	virtual void speak1(){
		cout << "动物在唱歌..." << endl;
	}
};

class Dog : public Animal{
public:
	void speak(){
		cout << "小狗在唱歌..." << endl;
	}
	void speak1(){
		cout << "小狗在唱歌..." << endl;
	}
};

void DoBussiness(Animal& animal){
	animal.speak();
	animal.speak1();
}

int main(){
	Dog dog;
    //这里的运行结果，是"动物在唱歌..."
    //我们的期望是能够自动调用子类的方法
	//解决办法，如speak1所示，在基类speak1前面加virtual(虚函数)
	DoBussiness(dog);

    return 0;
}

#include <iostream>
using namespace std;
/*
可以把C++的class当成struct看待，子类是父类的成员叠加子类的成员而成。
*/
class Eclass{

};
class Aclass{
public:
	int mA;
	int mB;
};
class Bclass : public Aclass{
public:
	int mC;
};
class Cclass : public Bclass{
public:
	int mD;
};

int main(){
	//C++规定空类(Eclass)大小为1字节
	cout << "E size:" << sizeof(Eclass) << endl;
	cout << "A size:" << sizeof(Aclass) << endl;
	cout << "B size:" << sizeof(Bclass) << endl;
	cout << "C size:" << sizeof(Cclass) << endl;

    return 0;
}

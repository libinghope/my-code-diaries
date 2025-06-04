//typeid是c++中才有的这里先提前认识下
#include<iostream>//此时文件后缀如果是c，而不是是cpp，编译器提示有错
using namespace std;
#if 0
struct  Person{
    char name[128];
    int age;
}

typedef struct Person MyPerson
#endif

typedef struct Person
{
	char name[128];
	int age;
}MyPerson;

typedef char* PCHAR;

//typeid可以查看类型信息
void testTypeID(){
    char *p1, *p2;

    cout << typeid(p1).name() << endl;
    cout << typeid(p2).name() << endl;

}



int main(){
    testTypeID();

    
    system("pause");
    return 0;
}
#include <iostream>
using namespace std;

class Person
{
public:
    static const int mShare1 = 11;//static 在前在后都可以
    const static int mShare2 = 10; //只读区，不可修改
};
int main()
{

    cout << "Person::mShare1=" << Person::mShare1 << endl;
    cout << "Person::mShare2=" << Person::mShare2 << endl;

    return 0;
}

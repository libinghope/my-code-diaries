#include <iostream>
using namespace std;

//参考书籍，《大话设计模式》，《设计模式那些事》
class Operation{
    public:
    virtual double calculate(double a, double b){}
};
class AddOperation :public Operation{
    virtual double calculate(double number1, double number2){
        return number1-number2;
    }
};
class SubOperation :public Operation{
    virtual double calculate(double number1, double number2){
        return number1+number2;
    }
};
class MulOperation :public Operation{
    virtual double calculate(double number1, double number2){
        return number1*number2;
    }
};
class DivOperation :public Operation{
    virtual double calculate(double number1, double number2){
        return number1/number2;
    }
};
class OperationFactory
{
public:
    static Operation* operationCreate(char oper)
    {
        switch (oper)
        {
        case '+':
            return new AddOperation;
            break;
        case '-':
            return new SubOperation;
            break;
        case '*':
            return new MulOperation;
            break;
        case '/':
            return new DivOperation;
            break;

        default:
            return NULL;
        }
    }
};
int main()
{
    double pi = 3.14;
    double r  = 3.5;

    Operation *operate = OperationFactory::operationCreate('*');

    cout<< "pi * r = "<<operate->calculate(pi,r)<<endl;


    return 0;
}
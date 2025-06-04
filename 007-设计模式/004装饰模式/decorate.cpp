#include<iostream>
#include"decorate.h"
using namespace std;

FineryDecoration::FineryDecoration(Component *c){
    this->component = c;
}
void Avatar::show(){
    cout<<"Avatar 的装饰有:"<<endl;
}

TShirts::TShirts(Component *c):FineryDecoration(c){
    component = c;
}

void TShirts::show(){
    this->component->show();
    cout<<"穿上T恤."<<endl;
}

BellBottoms::BellBottoms(Component *c):FineryDecoration(c){
    this->component = c;
}
void BellBottoms::show(){
    component->show();
    cout<<"穿上喇叭裤."<<endl;
}
PoSneakers::PoSneakers(Component *c):FineryDecoration(c){
    component = c;
}
void PoSneakers::show(){
    component->show();
    cout<<"穿上破球鞋."<<endl;
}

int main(){
    Avatar avatar;
    TShirts tshirts(&avatar);
    BellBottoms bellbottoms(&tshirts);
    PoSneakers posneakers(&bellbottoms);

    //在装饰模式中，装饰的顺序是很重要的，先穿裤子再穿内裤就成了”超人“了。
    posneakers.show();
    return 0;
}
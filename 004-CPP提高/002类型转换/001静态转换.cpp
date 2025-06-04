class Animal{};
class Dog : public Animal{};
class Other{};

//基础数据类型转换
void test01(){
	char a = 'a';
	double b = static_cast<double>(a);
}

//继承关系指针互相转换
void test02(){
	//继承关系指针转换
	Animal* animal01 = nullptr;
	Dog* dog01 = nullptr;
	//子类指针转成父类指针,安全
	Animal* animal02 = static_cast<Animal*>(dog01);
	//父类指针转成子类指针，不安全
	Dog* dog02 = static_cast<Dog*>(animal01);
}

//继承关系引用相互转换
void test03(){

	Animal ani_ref;
	Dog dog_ref;
	//继承关系指针转换
	Animal& animal01 = ani_ref;
	Dog& dog01 = dog_ref;
	//子类指针转成父类指针,安全
	Animal& animal02 = static_cast<Animal&>(dog01);
	//父类指针转成子类指针，不安全
	Dog& dog02 = static_cast<Dog&>(animal01);
}

//无继承关系指针转换
void test04(){
	
	Animal* animal01 = nullptr;
	Other* other01 = nullptr;

	//转换失败
	//Animal* animal02 = static_cast<Animal*>(other01);
}

int main(){
    test01();
    test02();
    test03();
    test04();

    return;
}
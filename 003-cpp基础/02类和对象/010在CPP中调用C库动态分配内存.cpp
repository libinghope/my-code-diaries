#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//memory allocation的缩写: malloc
//为了使用c的动态内存分配函数在堆上创建一个类的实例，我们必须这样做:
class Person{
public:
	Person(){
		mAge = 20;
        //先开辟空间再赋值，很傻x
		pName = (char*)malloc(strlen("john")+1);
		strcpy(pName, "john");
	}
	void Init(){
		mAge = 20;
		pName = (char*)malloc(strlen("john")+1);
		strcpy(pName, "john");
	}
	void Clean(){
		if (pName != NULL){
			free(pName);
		}
	}
public:
	int mAge;
	char* pName;
};
int main(){

	//分配内存
	Person* person = (Person*)malloc(sizeof(Person));
	if(person == NULL){
		return 0;
	}
	//调用初始化函数
	person->Init();
	//清理对象
	person->Clean();
	//释放person对象
	free(person);

	return 0;
}

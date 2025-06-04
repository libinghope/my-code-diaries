#include<iostream>
using namespace std;

void TestFunction(){
	
	cout << "开始抛出异常..." << endl;
	//throw 10; //抛出int类型异常
	//throw 'a'; //抛出char类型异常
	//throw "abcd"; //抛出char*类型异常
	string ex = "string exception!";
	throw ex;

}

//捕捉异常的方式是通过严格类型匹配。是什么类型就会进入对应的catch
int main(){
    	try{
		TestFunction();
	}
	catch (int){
		cout << "抛出Int类型异常!" << endl;
	}
	catch (char){
		cout << "抛出Char类型异常!" << endl;
	}
	catch (char*){
		cout << "抛出Char*类型异常!" << endl;
	}
	catch (string){
		cout << "抛出string类型异常!" << endl;
	}
	//捕获所有异常
	catch (...){
		cout << "抛出其他类型异常!" << endl;
	}

    return 0;
}
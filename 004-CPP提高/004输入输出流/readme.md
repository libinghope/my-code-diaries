# 流的概念和流类库的结构

这些东西用到的时候再查吧  

程序的输入指的是从输入文件将数据传送给程序，程序的输出指的是从程序将数据传送给输出文件。  
C++输入输出包含以下三个方面的内容：  
    1、对系统指定的标准设备的输入和输出。即从键盘输入数据，输出到显示器屏幕。这种输入输出称为标准的输入输出，简称标准I/O。  
    2、以外存磁盘文件为对象进行输入和输出，即从磁盘文件输入数据，数据输出到磁盘文件。以外存文件为对象的输入输出称为文件的输入输出，简称文件I/O。  
    3、对内存中指定的空间进行输入和输出。通常指定一个字符数组作为存储空间(实际上可以利用该空间存储任何信息)。这种输入和输出称为字符串输入输出，简称串I/O。  

C++编译系统提供了用于输入输出的iostream类库。iostream这个单词是由3个部 分组成的，即i-o-stream，意为输入输出流。在iostream类库中包含许多用于输入输出的 类。常用的见表
![常用输入输出流类.png](https://i.loli.net/2020/03/09/YutRFwa2NHTMqo8.png)

ios是抽象基类，由它派生出istream类和ostream类，两个类名中第1个字母i和o分别代表输入(input)和输出(output)。 istream类支持输入操作，ostream类支持输出操作， iostream类支持输入输出操作。iostream类是从istream类和ostream类通过多重继承而派生的类。其继承层次见上图表示。
C++对文件的输入输出需要用ifstrcam和ofstream类，两个类名中第1个字母i和o分别代表输入和输出，第2个字母f代表文件 (file)。ifstream支持对文件的输入操作， ofstream支持对文件的输出操作。类ifstream继承了类istream，类ofstream继承了类ostream，类fstream继承了 类iostream。见图 
![继承关系.png](https://i.loli.net/2020/03/09/c6vKCdZEzIjfmH3.png)

I/O类库中还有其他一些不经常使用的类，不在赘述。  
与iostream类库有关的头文件  
iostream类库中不同的类的声明被放在不同的头文件中，用户在自己的程序中用#include命令包含了有关的头文件就相当于在本程序中声明了所需 要用到的类。可以换 —种说法：头文件是程序与类库的接口，iostream类库的接口分别由不同的头文件来实现。常用的有  
•iostream  包含了对输入输出流进行操作所需的基本信息。  
•fstream  用于用户管理的文件的I/O操作。  
•strstream  用于字符串流I/O。  
•stdiostream  用于混合使用C和C + +的I/O机制时，例如想将C程序转变为C++程序。  
•iomanip  在使用格式化I/O时应包含此头文件。

在iostream头文件中定义的流对象  
在 iostream 头文件中定义的类有 ios，istream，ostream，iostream，istream 等。  

在iostream头文件中不仅定义了有关的类，还定义了4种流对象，
| 对象 | 含义       | 对应设备 | 对应的类           | c语言中相应的标准文件 |
| ---- | ---------- | -------- | ------------------ | --------------------- |
| cin  | 标准输入流 | 键盘     | istream_withassign | stdin                 |
| cout | 标准输出流 | 屏幕     | ostream_withassign | stdout                |
| cerr | 标准错误流 | 屏幕     | ostream_withassign | stderr                |
| clog | 标准错误流 | 屏幕     | ostream_withassign | stderr                |

在iostream头文件中定义以上4个流对象用以下的形式（以cout为例）：  
ostream cout ( stdout);  
在定义cout为ostream流类对象时，把标准输出设备stdout作为参数，它就与标准输出设备(显示器)联系起来，如果有  
cout <<3;
就会在显示器的屏幕上输出3。  

在iostream头文件中重载运算符
“<<”和“>>”本来在C++中是被定义为左位移运算符和右位移运算符的，由于在iostream头文件中对它们进行了重载， 使它们能用作标准类型数据的输入和输出运算符。所以，在用它们的程序中必须用#include命令把iostream包含到程序中。  

 >#include \<iostream\>  
1 \>\>a表示将数据放入a对象中。  
2 \<\<a表示将a对象中存储的数据拿出。

标准I/O流
标准I/O对象:cin，cout，cerr，clog  
cout流对象  
cout是console output的缩写，意为在控制台（终端显示器）的输出。  

强调几点:  
1 cout不是C++预定义的关键字，它是ostream流类的对象，在iostream中定义。 顾名思义，流是流动的数据，cout流是流向显示器的数据。cout流中的数据是用流插入运算符“<<”顺序加入的。  
2 如果有:  
cout<<"I "<<"study C++ "<<"very hard. << “hello world !";
按顺序将字符串"I ", "study C++ ", "very hard."插人到cout流中，cout就将它们送到显示器，在显示器上输出字符串"I study C++ very hard."。cout流是容纳数据的载体，它并不是一个运算符。人们关心的是cout流中的内容，也就是向显示器输出什么。  

3 用“cout<<”输出基本类型的数据时，可以不必考虑数据是什么类型，系统会判断数据的类型，并根据其类型选择调用与之匹配的运算符重 载函数。这个过程都是自动的，用户不必干预。如果在C语言中用prinf函数输出不同类型的数据，必须分别指定相应的输出格式符，十分麻烦，而且容易出错。C++的I/O机制对用户来说，显然是方便而安全的。  

4 cout流在内存中对应开辟了一个缓冲区，用来存放流中的数据，当向cout流插人一个endl时，不论缓冲区是否已满，都立即输出流中所有数据，然后插入一个换行符， 并刷新流（清空缓冲区）。注意如果插人一个换行符”\n“（如cout\<\<a<<"\n"），则只输出和换行，而不刷新cout 流(但并不是所有编译系统都体现出这一区别）。  

5 在iostream中只对"<<"和">>"运算符用于标准类型数据的输入输出进行了重载，但未对用户声明的类型数据的输入输出进行重载。如果用户声明了新的类型，并希望用"<<"和">>"运算符对其进行输入输出，按照重运算符重载来做。  

cerr流对象:  
cerr流对象是标准错误流，cerr流已被指定为与显示器关联。cerr的 作用是向标准错误设备(standard error device)输出有关出错信息。cerr与标准输出流cout的作用和用法差不多。但有一点不同：cout流通常是传送到显示器输出，但也可以被重定向输出到磁盘文件，而cerr流中的信息只能在显示器输出。当调试程序时，往往不希望程序运行时的出错信息被送到其他文件，而要求在显示器上及时输出，这时 应该用cerr。cerr流中的信息是用户根据需要指定的。  

clog流对象:  
clog流对象也是标准错误流，它是console log的缩写。它的作用和cerr相同，都是在终端显示器上显示出错信息。区别：cerr是不经过缓冲区，直接向显示器上输出有关信息，而clog中的信息存放在缓冲区中，缓冲区满后或遇endl时向显示器输出。

缓冲区的概念:  
![image.png](https://i.loli.net/2020/03/09/KPA5rnsRjlJb7LQ.png)  
输入输出是相当于应用程序(内存)来说的

标准输入流
标准输入流对象cin，重点掌握的函数  

```cpp
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
//cin.get
void test01(){
#if 0
char ch = cin.get();
cout << ch << endl;

cin.get(ch);
cout << ch << endl;


//链式编程
char char1, char2, char3, char4;
cin.get(char1).get(char2).get(char3).get(char4);

cout << char1 << " " << char2 << "" << char3 <<  " " << char4 << " ";
#endif

char buf[1024] = { 0 };
//cin.get(buf.1024);
cin.getline(buf,1024);
cout << buf;
}

//cin.ignore
void test02(){

char buf[1024] = { 0 };
cin.ignore(2); //忽略缓冲区当前字符
cin.get(buf,1024);
cout << buf << endl;
}

//cin.putback 将数据放回缓冲区
void test03(){

//从缓冲区取走一个字符
char ch = cin.get();
cout << "从缓冲区取走的字符:" << ch << endl;
//将数据再放回缓冲区
cin.putback(ch);
char buf[1024] = { 0 };
cin.get(buf,1024);
cout << buf << endl;

}

//cin.peek 偷窥
void test04(){

//偷窥下缓冲区的数据
char ch = cin.peek();
cout << "偷窥缓冲区数据:" << ch << endl;
char buf[1024] = { 0 };
cin.get(buf, 1024);
cout << buf << endl;
}

//练习  作业 使用cin.get和putback完成类似功能
void test05(){

cout << "请输入一个数字或者字符串:" << endl;
char ch = cin.peek();
if(ch >= '0' && ch <= '9'){
int number;
cin >> number;
cout << "数字:" << number << endl;
}
else{
char buf[64] = { 0 };
cin.getline(buf, 64);
cout << "字符串:" <<  buf << endl;
}
}

//标准输出流  
//字符输出:
cout.flush() //刷新缓冲区 Linux下有效
cout.put() //向缓冲区写字符
cout.write() //从buffer中写num个字节到当前输出流中。

//cout.flush 刷新缓冲区，linux下有效
void test01(){
cout << "hello world";
//刷新缓冲区
cout.flush();
}

//cout.put 输出一个字符
void test02(){

cout.put('a');
//链式编程
cout.put('h').put('e').put('l');
}

//cout.write 输出字符串 buf,输出多少个
void test03(){

//char* str = "hello world!";
//cout.write(str, strlen(str));
char* str = "*************";
for (int i = 1; i <= strlen(str); i ++){
cout.write(str, i);
cout << endl;
}

for (int i = strlen(str); i > 0; i --){
  cout.write(str, i);
  cout << endl;
 }

}
```

格式化输出:  
在输出数据时，为简便起见，往往不指定输出的格式，由系统根据数据的类型采取默认的格式，但有时希望数据按指定的格式输出，如要求以十六进制或八进制形式输出一个整数，对输出的小数只保留两位小数等。有两种方法可以达到此目的。  
1）使用控制符的方法；  
2）使用流对象的有关成员函数。  

使用流对象的有关成员函数  
通过调用流对象cout中用于控制输出格式的成员函数来控制输出格式。用于控制输出格式的常用的成员函数如下：  

流成员函数setf和控制符setiosflags括号中的参数表示格式状态，它是通过格式标志来指定的。格式标志在类ios中被定义为枚举值。因此在引用这些格式标志时要在前面加上类名ios和域运算符“::”。  
格式标志见表13.5。
![image.png](https://i.loli.net/2020/03/09/R83sWZSzHG2Ml4Q.png)

控制符格式化输出
C++提供了在输入输出流中使用的控制符(有的书中称为操纵符)。

```CPP
//通过流成员函数
void test01(){
 int number = 99;
 cout.width(20);
 cout.fill('*');
 cout.setf(ios::left);
 cout.unsetf(ios::dec); //卸载十进制
 cout.setf(ios::hex);
 cout.setf(ios::showbase);
 cout.unsetf(ios::hex);
 cout.setf(ios::oct);
 cout << number << endl;
}

//使用控制符
void test02(){

int number = 99;
cout << setw(20)<< setfill('~') << setiosflags(ios::showbase)<<setiosflags(ios::left)<< hex << number<< endl;

}
```

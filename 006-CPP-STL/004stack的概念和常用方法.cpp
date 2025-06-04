/*一种先进后出的数据结构，在数据结构篇章已经实现了数组栈和链表栈*/

//stack的常用api
stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式： 
stack(const stack &stk);//拷贝构造函数
//stack赋值操作
stack& operator=(const stack &stk);//重载等号操作符
//stack数据存取操作
push(elem);//向栈顶添加元素
pop();//从栈顶移除第一个元素
top();//返回栈顶元素
//stack大小操作
empty();//判断堆栈是否为空
size();//返回堆栈的大小

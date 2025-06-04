/*
队列，顾名思义跟排队一样，先进先出，
在数据结构中已经实现过,不在赘述
*/

//queue常用API

//queue构造函数
queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
queue(const queue &que);//拷贝构造函数
//queue存取、插入和删除操作
push(elem);//往队尾添加元素
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素

//queue赋值操作
queue& operator=(const queue &que);//重载等号操作符
//queue大小操作
empty();//判断队列是否为空
size();//返回队列的大小

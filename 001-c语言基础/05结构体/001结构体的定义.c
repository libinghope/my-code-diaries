//结构体类型的定义
struct stu
{
	char name[50];
	int age;
};

//先定义类型，再定义变量（常用）
struct stu s1 = { "mike", 18 };


//定义类型同时定义变量
struct stu2
{
	char name[50];
	int age;
}s2 = { "lily", 22 };

struct
{
	char name[50];
	int age;
}s3 = { "yuri", 25 };

#include <stdio.h>

/*(相当于给类型再起一个新名字)
typedef为C语言的关键字，作用是为一种数据类型(基本类型或自定义数据类型)
定义一个新名字，不能创建新类型。
	与#define不同，typedef仅限于数据类型，而不是能是表达式或具体的值
	#define发生在预处理，typedef发生在编译阶段
*/

typedef int INT;
typedef char BYTE;
typedef BYTE T_BYTE;
typedef unsigned char UBYTE;

typedef struct type
{
	UBYTE a;
	INT b;
	T_BYTE c;
}TYPE, *PTYPE;

int main()
{
	TYPE t;
	t.a = 254;
	t.b = 10;
	t.c = 'c';

	PTYPE p = &t;
	printf("%u, %d, %c\n", p->a, p->b, p->c);

	return 0;
}

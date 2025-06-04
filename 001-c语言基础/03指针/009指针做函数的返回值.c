#include <stdio.h>

int a = 10;

int *getA()
{
	return &a;
}


int main()
{
	*( getA() ) = 111;
	printf("a = %d\n", a);

	return 0;
}

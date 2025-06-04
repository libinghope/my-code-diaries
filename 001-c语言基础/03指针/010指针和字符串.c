#include <stdio.h>
#include <stdlib.h>

void mystrcat(char *dest, const char *src)
{
	int len1 = 0;
	int len2 = 0;
	while (dest[len1])
	{
		len1++;
	}
	while (src[len2])
	{
		len2++;
	}

	int i;
	for (i = 0; i < len2; i++)
	{
		dest[len1 + i] = src[i];
	}
}

int main()
{
	char str[] = "hello world";
	char *p = str;
	*p = 'm';
	p++;
	*p = 'i';
	printf("%s\n", str);

	p = "mike jiang";
	printf("%s\n", p);

	char *q = "test";
	printf("%s\n", q);


    char dst[100] = "hello mike";
	char src[] = "123456";
	
	mystrcat(dst, src);
	printf("dst = %s\n", dst);


	return 0;
}

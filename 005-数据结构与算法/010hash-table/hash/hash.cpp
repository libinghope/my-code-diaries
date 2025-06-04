#include <math.h>
//快速进行哈希计算
int Hash(const char *Key, int TableSize)
{
    unsigned int h = 0; /* 散列函数值，初始化为0 */

    while (*Key != '\0') /* 位移映射 */
        h = (h << 5) + *Key++;

    return h % TableSize;
}

int Hash(const int Key, int TableSize)
{
    unsigned int h = 0; /* 散列函数值，初始化为0 */
    int len = getIntLen(Key);
    int b = 1;
    for (int i = 1; i < len; i++) //(123 / 1000 % 10 = 1)(123 / 100 % 10 = 2)(123 / 1 % 10 = 3)
    {
        b *= 10;
    }
    while (b >= 1)
    {
        //* 位移映射
        //int tmp = (Key / b) % 10; //从高到低取出各位数字
        h = (h << 5) + (Key / b) % 10;
        b /= 10;
    }
    return h % TableSize;
}

//计算整数的位数
int getIntLen(int N)
{
    int len = 0;
    while (N != 0)
    {
        N /= 10;
        len++;
    }
    return len;
}

//寻找不小N的下一个素数
static int NextPrime( int N )
{
    int i;

    if( N % 2 == 0 )  N++;
    for( ; ; N += 2 ) {
        for( i = 3; i * i <= N; i += 2 )
            if( N % i == 0 )   break;
            if(i * i > N) return N;             
    }
}
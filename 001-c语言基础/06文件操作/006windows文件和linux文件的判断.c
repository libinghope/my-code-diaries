#include <stdio.h>
#include <stdlib.h>
/*
Windows和Linux文本文件区别
	b是二进制模式的意思，b只是在Windows有效，在Linux用r和rb的结果是一样的
	Unix和Linux下所有的文本文件行都是\n结尾，而Windows所有的文本文件行都是\r\n结尾
	在Windows平台下，以“文本”方式打开文件，不加b：
	    当读取文件的时候，系统会将所有的 "\r\n" 转换成 "\n"
	    当写入文件的时候，系统会将 "\n" 转换成 "\r\n" 写入 
	以"二进制"方式打开文件，则读\写都不会进行这样的转换
	在Unix/Linux平台下，“文本”与“二进制”模式没有区别，"\r\n" 作为两个字符原样输入输出
*/

int main(int argc, char *args[])
{
    if (argc < 2)
        return 0;

    FILE *p = fopen(args[1], "rb");
    if (!p)
        return 0;

    char a[1024] = {0};
    fgets(a, sizeof(a), p);

    int len = 0;
    while (a[len])
    {
        if (a[len] == '\n')
        {
            if (a[len - 1] == '\r')
            {
                printf("windows file\n");
            }
            else
            {
                printf("linux file\n");
            }
        }
        len++;
    }

    fclose(p);

    /*重命名文件 删除文件  更新文件缓冲区
    int remove(const char *pathname);
    功能：删除文件
    参数：
        pathname：文件名
    返回值：
	成功：0
	失败：-1


    int rename(const char *oldpath, const char *newpath);
    功能：把oldpath的文件名改为newpath
    参数：
        oldpath：旧文件名
        newpath：新文件名
    返回值：
    成功：0
    失败： - 1

    int fflush(FILE *stream);
    功能：更新缓冲区，让缓冲区的数据立马写到文件中。
    参数：
        stream：文件指针
    返回值：
    成功：0
    失败：-1
    */

    system("pause");
    return 0;
}
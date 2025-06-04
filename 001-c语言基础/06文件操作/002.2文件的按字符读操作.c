#include <stdio.h>
#include <stdlib.h>
/*
在C语言中，EOF表示文件结束符(end of file)。
这种以EOF作为文件结束标志的文件，必须是文本文件。在文本文件中，
数据都是以字符的ASCII代码值的形式存放。
我们知道，ASCII代码值的范围是0~127，不可能出现-1，
因此可以用EOF作为文件结束标志。
EOF的定义如下
#define EOF     (-1)
当把数据以二进制形式存放到文件中时，就会有-1值的出现，
因此不能采用EOF作为二进制文件的结束标志。为解决这一个问题，
ANSI C提供一个feof函数，用来判断文件是否结束。feof函数既可用以判断
二进制文件又可用以判断文本文件。
*/
int main(){
    FILE * pFile = NULL;
    pFile = fopen("test.txt", "r");//以只读方式打开一个文件
    char ch;
    int i = 0;
    while ((ch = fgetc(pFile)) != EOF)//EOF只能判断文本文件
    {
        ++i;
        printf("%d：%c\n", i, ch);
    }

#ifdef IS_NOT_TEXT//读取非文本文件，判断是否到结尾
    while (!feof(pFile)) //文件没有结束，则执行循环
    {
        ch = fgetc(pFile);
        printf("%c", ch);
    }
#endif

    fclose(pFile);

    system("pause");
    return 0;
}
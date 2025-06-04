#include <stdio.h>

/*文件的打开方式
打开模式	 含义
r或rb	    以只读方式打开一个文本文件（不创建文件，若文件不存在则报错）
w或wb	    以写方式打开文件(如果文件存在则清空文件，文件不存在则创建一个文件)
a或ab	    以追加方式打开文件，在末尾添加内容，若文件不存在则创建文件
r+或rb+	    以可读、可写的方式打开文件(不创建新文件)
w+或wb+	    以可读、可写的方式打开文件(如果文件存在则清空文件，文件不存在则创建一个文件)
a+或ab+	    以添加方式打开文件，打开文件并在末尾更改文件,若文件不存在则创建文件

*/

int main(){
    FILE * pFile = NULL;
    pFile = fopen("test.txt", "w");//以写的方式打开一个文件
    char buf[] = "this is a test for fputc";
    int i = 0;
    int n = strlen(buf);
    for (i = 0; i < n; i++)
    {
        //往文件fp写入字符buf[i]
        int ch = fputc(buf[i], pFile);
        printf("ch = %c\n", ch);
    }
    fclose(pFile);
}
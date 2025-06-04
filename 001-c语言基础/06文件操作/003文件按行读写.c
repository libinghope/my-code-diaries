#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fp = fopen("test.txt", "w+");
    char *buf[] = { "123456\n", "bbbbbbbbbb\n", "ccccccccccc\n" };
    int i = 0;
    int n = 3;
    //写操作
    for (i = 0; i < n; i++)
    {
        int len = fputs(buf[i], fp);
        printf("len = %d\n", len);
    }

    char buf[100] = 0;

    //读操作
    while (!feof(fp)) //文件没有结束
    {
        memset(buf, 0, sizeof(buf));
        char *p = fgets(buf, sizeof(buf), fp);
        if (p != NULL)
        {
            printf("buf = %s", buf);
        }
    }
    fclose(fp);


    /*另外也可以按照格式化的方法读写文件,
     使用fprintf,fscanf方法,跟printf,scanf一样的用法，不再赘述
    */


    system("pause");
    return 0;
}
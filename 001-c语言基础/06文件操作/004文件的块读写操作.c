#include <stdio.h>
#include <stdlib.h>

typedef struct Stu
{
    char name[50];
    int id;
} Stu;

int main()
{

    FILE *pFile = fopen("test.txt", "w+");
    Stu s[3];
    int i = 0;
    for (i = 0; i < 3; i++)
    { //写入一些数据
        sprintf(s[i].name, "stu%d%d%d", i, i, i);
        s[i].id = i + 1;
    }

    int ret = fwrite(s, sizeof(Stu), 3, pFile);
    printf("ret = %d\n", ret);

    //把写入的数据读取出来
    Stu ss[3];
    int r = fread(ss, sizeof(Stu), 3, pFile);
    printf("ret = %d\n", r);

    for (int i = 0; i < 3; i++)
    {
        printf("ss = %s, %d\n", ss[i].name, ss[i].id);
    }

    fclose(pFile);
    system("pause");
    return 0;
}
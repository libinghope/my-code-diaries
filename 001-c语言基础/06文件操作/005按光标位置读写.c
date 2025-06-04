#include <stdio.h>
typedef struct Stu
{
    char name[50];
    int id;
} Stu;

int main()
{
    //假如已经往文件写入3个结构体
    //fwrite(s, sizeof(Stu), 3, fp);

    Stu s[3];
    Stu tmp;
    int ret = 0;
    FILE * pFile = fopen("test.txt", "w+");

    //文件光标读写位置从开头往右移动2个结构体的位置
    fseek(pFile, 2 * sizeof(Stu), SEEK_SET);

    //读第3个结构体
    ret = fread(&tmp, sizeof(Stu), 1, pFile);
    if (ret == 1)
    {
        printf("[tmp]%s, %d\n", tmp.name, tmp.id);
    }

    //把文件光标移动到文件开头
    //fseek(fp, 0, SEEK_SET);
    rewind(pFile);

    ret = fread(s, sizeof(Stu), 3, pFile);
    printf("ret = %d\n", ret);

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("s === %s, %d\n", s[i].name, s[i].id);
    }

    fclose(pFile);
    
    system("pause");
    return 0;
}
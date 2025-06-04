#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef struct _Student
{
    int sid;
    char sname[20];
} Student;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("./a.out filename\n");
        return -1;
    }

    // 1. open file
    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);
    int length = sizeof(Student);

    ftruncate(fd, length);

    // 2. mmap
    Student *stu = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (stu == MAP_FAILED)
    {
        perror("mmap err");
        return -1;
    }
    int num = 1;
    // 3. 修改内存数据
    while (1)
    {
        stu->sid = num;
        sprintf(stu->sname, "xiaoming-%03d", num++);
        sleep(1); //相当于没隔1s修改一次映射区的内容
    }
    // 4. 释放映射区和关闭文件描述符
    munmap(stu, length);
    close(fd);

    return 0;
}

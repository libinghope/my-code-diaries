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
    //open file
    int fd = open(argv[1], O_RDWR);
    //mmap
    int length = sizeof(Student);
    Student *stu = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (stu == MAP_FAILED)
    {
        perror("mmap err");
        return -1;
    }
    //read data
    while (1)
    {
        printf("sid=%d,sname=%s\n", stu->sid, stu->sname);
        sleep(1);
    }
    //close and munmap
    munmap(stu, length);
    close(fd);
    return 0;
}

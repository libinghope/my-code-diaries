#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);

    pid_t pid = fork();
    if (pid == 0)
    {
        //son
        //son -- > ps
        //关闭 读端
        close(fd[0]);
        //1. 先重定向
        dup2(fd[1], STDOUT_FILENO); //标准输出重定向到管道写端
        //2. execlp
        execlp("ps", "ps", "aux", NULL);
    }
    else if (pid > 0)
    {
        //parent
        //关闭写端
        close(fd[1]);
        //1. 先重定向，标准输入重定向到管道读端
        dup2(fd[0], STDIN_FILENO);
        //2. execlp
        execlp("grep", "grep", "bash", NULL);
    }

    return 0;
}

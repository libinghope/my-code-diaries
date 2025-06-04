#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);
    pid_t pid;
    int n = 2, i = 0;
    for (i = 0; i < n; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            break;
        }
    }

    //i = 0 ,代表兄长，1 - 代表弟弟，2- 父亲
    if (i == 0)
    {
        //兄长进程
        //1. 关闭读端
        close(fd[0]);
        //2. 重定向
        dup2(fd[1], STDOUT_FILENO);
        //3. 执行 execlp
        execlp("ps", "ps", "aux", NULL);
    }
    else if (i == 1)
    {
        //弟弟
        //1. 关闭写端
        close(fd[1]);
        //2. 重定向
        dup2(fd[0], STDIN_FILENO);
        //3. 执行ececlp
        execlp("grep", "grep", "bash", NULL);
    }
    else if (i == 2)
    {
        //parent
        //父亲需要关闭读写两端
        close(fd[0]);
        close(fd[1]);
        //回收子进程
        wait(NULL);
        wait(NULL);
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0)
    {
        //son
        sleep(3);
        close(fd[0]); //关闭读端
        write(fd[1], "hello", 5);
        close(fd[1]);
        while (1)
        {
            sleep(1);
        }
    }
    else if (pid > 0)
    {
        //parent
        close(fd[1]); //关闭写端
        close(fd[0]);
        int status;
        wait(&status);
        if (WIFSIGNALED(status))
        {
            printf("killed by %d\n", WTERMSIG(status));
        }
        //父进程只是关闭读写两端，但是不退出
        while (1)
        {
            sleep(1);
        }

        char buf[12] = {0};
        while (1)
        {

            int ret = read(fd[0], buf, sizeof(buf));
            if (ret == 0)
            {
                printf("read over!\n");
                break;
            }
            if (ret > 0)
            {
                write(STDOUT_FILENO, buf, ret);
            }
        }
    }
    return 0;
}

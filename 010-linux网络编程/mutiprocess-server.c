#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "wrap.h"

/* waitpid 函数详解
原型: pid_t waitpid(pid_t pid, int *status, int options);
pid:
    pid>0    只等待进程ID等于pid的子进程，不管其它已经有多少子进程运行结束退出了，只要指定的子进程还没有结束，waitpid就会一直等下去。
    pid=-1    等待任何一个子进程退出，没有任何限制，此时waitpid和wait的作用一模一样。
    pid=0时   等待同一个进程组中的任何子进程，如果子进程已经加入了别的进程组，waitpid不会对它做任何理睬。
    pid<-1    等待一个指定进程组中的任何子进程，这个进程组的ID等于pid的绝对值。

status: 如果不是一个空指针,则终止进程的终止状态就存放在status所指向的单元。参数status如果是一个空指针,则表示父进程不关心子进程的终止状态

option:
    WNOHANG    若由pid指定的子进程未发生状态改变(没有结束)，则waitpid()不阻塞，立即返回0
    WUNTRACED    返回终止子进程信息和因信号停止的子进程信息
    WCONTINUED    返回收到SIGCONT信号而恢复执行的已停止子进程状态信息

返回值：
    成功    成功结束运行的子进程的进程号
    失败    返回-1
    WNOHANG    没有子进程退出返回0
*/
#define MAXLINE 80
#define SERV_PORT 800

void do_sigchild(int num)
{
    while (waitpid(0, NULL, WNOHANG) > 0);
}
int main(void)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n;
    pid_t pid;

    struct sigaction newact;
    newact.sa_handler = do_sigchild;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGCHLD, &newact, NULL);

    //指定为TCP连接
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    Listen(listenfd, 20);

    printf("Accepting connections ...\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);

        /*fork系统调用用于创建一个新进程，称为子进程，它与进行fork()调用的进程(父进程)并发运行。
        创建新的子进程后，两个进程都将执行fork()系统调用之后的下一条指令。子进程使用相同的PC(程序计数器)，
        相同的CPU寄存器，相同的打开文件，这些文件在父进程中使用。fork()在子进程中返回0，向父进程返回正整数。
        实质是内部调用了copy_process拷贝父进程的PCB*/
        pid = fork();//fork出子进程
        if (pid == 0) {//子进程
            Close(listenfd);
            while (1) {
                n = Read(connfd, buf, MAXLINE);
                if (n == 0) {
                    printf("the other side has been closed.\n");
                    break;
                }
                printf("received from %s at PORT %d\n",
                        inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
                        ntohs(cliaddr.sin_port));
                for (i = 0; i < n; i++)
                    buf[i] = toupper(buf[i]);
                Write(connfd, buf, n);//小写转大写发回去
            }
            Close(connfd);
            return 0;
        } else if (pid > 0) {//父进程
            Close(connfd);
        } else
            perr_exit("fork");
    }
    Close(listenfd);
    return 0;
}
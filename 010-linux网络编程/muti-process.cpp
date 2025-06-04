#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include <iostream>
#include <sys/wait.h>

using namespace std;

// 进程退出函数
void print_exit()
{
    printf("the exit pid:[%d] \n", getpid());
}

int main()
{
    string sMatch;
    pid_t pid, child_pid;
    vector<string> provList;
    provList.push_back("taskFace");
    provList.push_back("taskObj");
    provList.push_back("taskAction");
    provList.push_back("taskHat");
    provList.push_back("taskOther");

    cout << "Main process,id=" << getpid() << endl;

    // 循环处理"100,200,300,400,500"
    for (vector<string>::iterator it = provList.begin(); it != provList.end(); ++it)
    {
        sMatch = *it;
        atexit(print_exit);
        pid = fork(); //就相当于一棵树在这里分叉了
        // (*hsq*)子进程退出循环，不再创建子进程，全部由主进程创建子进程，这里是关键所在
        if (pid == 0 || pid == -1)
        {
            break;
        }
    }

    if (pid == -1)
    {
        cout << "Fail to fork!" << endl;
        exit(1);
    }
    else if (pid == 0)
    {
        // 子进程处理逻辑
        cout << "This is children process,id=" << getpid() << ",start to process " << sMatch << endl;
        sleep(10);
        exit(0);
    }
    else
    {
        // 主进程处理逻辑
        cout << "This is main process,id=" << getpid() << ",end to process " << sMatch << endl;

        do
        {
            // WNOHANG 非阻塞 轮询 等待带子进程结束
            child_pid = waitpid(pid, NULL, WNOHANG);
            if (child_pid != pid)
            {
                printf("---- watpid error!\n");
            }
            printf("I am main progress.The pid progress has not exited!\n");
            sleep(2);

        } while (child_pid == 0);
        exit(0);
    }

    return 0;
}
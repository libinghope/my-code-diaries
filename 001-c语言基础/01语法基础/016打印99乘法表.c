#include<stdio.h>
#include<stdlib.h>


int main(){
    //打印99乘法表
    for(int i = 1; i < 10; i++){
        for(int j = 1; j <= i; j++){
            printf("%d x %d = %d\t", j, i, i*j);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
//冒泡排序

void bubbleSort(int A[],int N){
    for(int i=0;i<N;i++){
        bool swap_flag = false;
        for(int j=0;j<N-i;j++){
            //保持稳定性，严格大于才交换,相等的要保持原本顺序
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swap_flag = true;
            }
        }
        if(!swap_flag){
            //全程无交换，说明已经排好了，不用继续进行了
            break;
        }
    }
}

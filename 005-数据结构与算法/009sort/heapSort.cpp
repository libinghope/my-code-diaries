//堆排序
void heapSort( int A[], int N ) 
{
    int i;
    int temp;

    //* 建立最大堆
    for( i = (N-1)/2; i >= 0; i-- )  /*从有儿子的最后一个结点开始*/
        Adjust(A, i, N); 
    for( i = N-1; i > 0; i-- ){
        /* 将堆顶元素A[0]与当前堆的最后一个元素A[i]换位 */
        temp = A[0]; A[0] = A[i]; A[i] = temp;
        /* 将有i个元素的新堆从根结点向下过滤调整 */
        Adjust(A, 0, i);
    }
}

void Adjust( int A[], int i, int N )
{    /* 对A[]中的前N个元素从第i个元素开始向下迁移调整 */
    int Child;
    int  temp;

    for( temp = A[i]; (2*i + 1) < N; i = Child){
        Child = (2*i + 1);  /* 左孩子节点 */
        if ( (Child != N-1) && A[Child + 1] > A[Child])
            Child++; /* Child指向左右子结点的较大者 */
        if( temp < A[Child] )
            A[i] = A[Child];  /* 移动Child元素到上层 */
        else    break;
    }
    A[i] = temp;    /*将temp放到当前位置　*/
}



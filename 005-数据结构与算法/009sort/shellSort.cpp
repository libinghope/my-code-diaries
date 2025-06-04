
/*希尔排序
定义增量序列 D(m)>D(m-1)>D(m-2)>...>D(1)=1
对每个D(k)进行“D(K)-间隔”排序(k=m,m-1,...,1)
比如 首先5间隔进行排序，然后3间隔排序...最后插入排序,即Incre[]={5,3,2,1}
一般情况下取D(m)=N/2,D(k)=D(k+1)/2，即每次减半
*/
void shellSort(int A[], int N, int Incre[], int M)
{
    //* 其中Incre[]为包含M个增量的序列，递减有序，且最后一个元素为1
    int i, j, k, Increment;
    int temp;

    for (i = 0; i < M; i++)
    {
        Increment = Incre[i]; //* 选择该趟排序需要的增量
        for (j = Increment; j < N; j++)
        {
            temp = A[j];
            for (k = j; k - Increment >= 0; k -= Increment)
            {
                if (temp >= A[k - Increment])
                    break;
                else
                    A[k] = A[k - Increment];
                A[k] = temp;
            }
        }
    }
}

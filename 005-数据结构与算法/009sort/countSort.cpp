/*计数排序
排序好的结果存放在sorted_arr
*/

void countSort(int *A, int N,int *sorted_arr)
{
    int *count_arr = new int[100];
    int  i, j, k;

    //　初始计数化数组
    for (k = 0; k < 100; k++)
        count_arr[k] = 0;
    
    // 步骤二， 计数
    for (i = 0; i < 100; i++)
        count_arr[i]++;
    
    // 步骤三， 对所有的计数累加（计算每个数的实际顺序）
    for (k = 1; k < 100; k++)
        count_arr[k] += count_arr[k-1];
    
    // 步骤4， 反向填充数组
    for (j = N; j > 0; j--)
        sorted_arr[--count_arr[A[j -1]]] = A[j -1];

    delete[] count_arr;
}
//插入排序
void insertSort(int A[], int N){
	int temp,i,j;
	for (i = 1; i < N; i++ ) {
		temp = A[i]; /* 取出未排序序列中的第一个元素*/
	    for (j = i; (j > 0) && (temp < A[j-1]); j-- )
			A[ j ] = A[ j - 1 ]; /*依次与已排序序列中元素比较并右移*/
		A[j] = temp; /* 放进合适的位置 */
	}
}

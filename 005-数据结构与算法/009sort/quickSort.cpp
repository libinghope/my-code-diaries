//快速排序
//时间复杂度 关键在于 主元 的选择，刚好在中间的话，速度很快
//可以选择 第一个 中间那个  最后一个  这三个数的中位数
void QuickSort(int A[], int N)
{
	QSort(A, 0, N - 1);
}

//* 对A[Low]~A[Hight]进行快速排序
void QSort(int A[], int Low, int High)
{
	int Pivot = A[Low]; /* 简单取首元素为基准 */
	int Left = Low, Right = High;

	if (Low >= High)
		return;
	Swap(&A[Low], &A[Right]); /*将基准与最后一个元素交换*/
	while (1)
	{ /*将序列中比基准小的移到基准左边，大的移到右边*/
		while ((Low < High) && (Pivot >= A[Low]))
			Low++;
		while ((Low < High) && (Pivot <= A[High]))
			High--;
		if (Low < High)
			Swap(&A[Low], &A[High]);
		else
			break;
	}
	Swap(&A[Low], &A[Right]); /* 将最后的基准换到正确的位置 */
	/*分别对两个子集进行快排*/
	QSort(A, Left, Low - 1);
	QSort(A, Low + 1, Right);
}

void Swap(int *a, int *b)
{ /*交换a和b两个元素*/
	int temp = *a;
	*a = *b;
	*b = temp;
}

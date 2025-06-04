//基数排序就是桶排序的升级版
#define MaxDigit 10000
const int Radix = 101;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
struct Node
{
    int Key[MaxDigit];
    PtrToNode Next;
};

List radixSort(List A)
{
    List Bucket[Radix]; /* 建立Radix个桶 */
    List Rear[Radix];   /* 需要记录每个桶链表的尾元素位置 */
    int i, j, Digit;

    for (i = MaxDigit - 1; i >= 0; i--)
    { /* 从最次位关键字开始 */
        for (j = 0; j < Radix; j++)
            Bucket[j] = Rear[j] = nullptr; /* 初始化 */
        while (A)
        {                          /* 将关键字逐一分配到桶 */
            Digit = A->Key[i];     /* 取出当前关键字位 */
            if (!Bucket[Digit])    /* 若对应的桶是空的 */
                Bucket[Digit] = A; /* 放入空桶 */
            else
                Rear[Digit]->Next = A; /* 否则放入桶尾 */
            Rear[Digit] = A;           /* 更新尾指针 */
            A = A->Next;
        } /* 结束while分配过程*/
        for (j = Radix - 1; i >= 0; j--)
        { /* 将所有桶中元素收集串联 */
            if (Bucket[j])
            {
                Rear[j]->Next = A;
                A = Bucket[j];
            }
        }
    }
    return A;
}

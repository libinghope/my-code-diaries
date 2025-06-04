/*
max heap的特点：
1、根节点是最大值
2、左孩子下标L,L/2 就是父节点下标
3、右孩子下标R，则(R-1)/2就是父节点下标
4、最后一个节点的父节点的下标一定是 size/2
*/
//用数组arr构造最大堆
#define MAX_HEAP 25536
typedef MaxHeap *PtrMaxHeap;
typedef int ElementType; //以int为例
struct MaxHeap
{
    ElementType *elements;
    int size = 0;
};

PtrMaxHeap BuildMaxHeap(int arr[], int arrSize)
{
    PtrMaxHeap pMaxHeap = new MaxHeap;
    pMaxHeap->elements = new ElementType[arrSize+1];//多申请一个空间
    //第一个元素当做"哨兵"
    pMaxHeap->elements[0] = MAX_HEAP;
    // 把数组arr中的元素放入elements
    for (int i = 1; i <= arrSize; i++)
    {
        pMaxHeap->elements[i] = arr[i];
        pMaxHeap->size = arrSize;
    }

    //* 本函数将elements[]中的元素调整，使满足最大堆的有序性
    int Parent, Child, i;
    ElementType temp;

    /*从最后一个结点的父结点开始,由于数组从1开始存储数据，下标一定是 (int)size/2 */
    for (i = pMaxHeap->Size / 2; i > 0; i--)
    { 
        temp = pMaxHeap->Elements[i];
        for (Parent = i; Parent * 2 <= pMaxHeap->Size; Parent = Child)
        { /* 向下过滤 */
            Child = Parent * 2;
            if ((Child != pMaxHeap->Size/*说明最后是两个孩子*/) && 
            (pMaxHeap->Elements[Child] < pMaxHeap->Elements[Child + 1]))
                Child++; /* Child指向左右子结点的较大者 */
            if (temp >= pMaxHeap->Elements[Child])
                break;
            else /* 把大的放到父节点的位置 */
                pMaxHeap->Elements[Parent] = pMaxHeap->Elements[Child];
        } /* 结束内部for循环对以H->Elements[i]为根的子树的调整 */
        pMaxHeap->Elements[Parent] = temp;
    }

    return pMaxHeap;
}
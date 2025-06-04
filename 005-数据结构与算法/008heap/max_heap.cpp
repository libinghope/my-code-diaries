//堆：用完全二叉树表示，每个子树的根节点都是所在子树最大值，用数组方式存储,
//存放数据的数组谢文彪与节点的位置存在着关系
//i是下标则 i/2 (整数部分)就是其父节点下标
#define HEAP_MAX 25536   //假设堆元素权值最大不超过25536
typedef int ElementType; //使用int作为元素类型

class MaxHeap
{
public:
    MaxHeap(int heapSize)
    {
        pDataArr = new ElementType[(heapSize + 1) * sizeof(ElementType)]; //多申请一个空间，除了0位置，其余用来保存完全二叉树
        size = 0;
        capacity = heapSize;
        pDataArr[0] = HEAP_MAX;
    }
    ~MaxHeap()
    {
        if (pDataArr)
        {
            delete[] pDataArr;
            pDataArr = nullptr;
        }
    }

    void insert(ElementType t)
    {
        if (full())
        {
            //throw "Max Heap is full !";
            return;
        }
        int i = ++size;
        for (; pDataArr[i / 2] < t; i /= 2) //T 需要重载<(小于号),利用下标与节点位置的关系,i/2
        {
            pDataArr[i] = pDataArr[i / 2];
        }
        pDataArr[i] = t;
    }

    void deleteMax ()
    {
        if (empty())
        {
            //throw "Max Heap is empty !";
            return;
        }
        int parent, child;
        ElementType maxItem, temp;
        maxItem = pDataArr[1]; //第一个根节点就是最大值

        temp = pDataArr[size--]; //最后一个
        for (parent = 1; parent * 2 < size; parent = child)
        {
            child = parent * 2;
            if (child != size && pDataArr[child] < pDataArr[child + 1])
            {
                child++;
            }
            if (temp >= pDataArr[child])
            {
                break;
            }
            else
            {
                pDataArr[parent] = pDataArr[child];
            }
        }
        pDataArr[parent] = temp;
    }

    inline bool full()
    {
        return size == capacity;
    }
    inline bool empty()
    {
        return 0 == size;
    }

private:
    ElementType *pDataArr; //存储堆元素的数组
    int size;
    int capacity;
};

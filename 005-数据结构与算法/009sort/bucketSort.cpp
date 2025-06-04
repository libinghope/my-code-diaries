//桶排序
/*
适用场合举例:假设一个学校有10000个学生，每个学生有自己的分数，分数处于[0-100]之间，给学生的成绩进行排序
就比较适合桶排序
*/
const int BUCKET_NUM = 10;
// 数据结构的定义，explicit表示不允许构造函数发生隐式转换
struct ListNode {
    explicit ListNode(int i = 0): mData(i), next(nullptr){};
    ListNode *next;
    int mData;
};

#include <vector>
using namespace std;
void bucketSort(int n,int arr[]){
    vector<ListNode*> buckets(BUCKET_NUM,(ListNode*)(0));

    // 将元素分配到桶
    for(int i=0;i<n;++i){
        int index = arr[i]/BUCKET_NUM;
        ListNode *head = buckets.at(index);
        buckets.at(index) = insert(head,arr[i]);
    }

    // 逐一合并各个桶
    ListNode *head = buckets.at(0);
    for(int i=1;i<BUCKET_NUM;++i){
        head = Merge(head,buckets.at(i));
    }
    //将排好序的元素写回原数组
    for(int i=0;i<n;++i){
        arr[i] = head->mData;
        head = head->next;
    }
}

ListNode *insert(ListNode *head, int val)
{
    ListNode dummyNode;                         // 节点指针
    ListNode *newNode = new ListNode(val);      //待插入的新节点
    ListNode *pre , *curr;
    dummyNode.next = head;                     // 将指针指向链表头部
    pre = &dummyNode;                           // 设置临时指针。pre是当前检查元素的上一个元素
    curr = head;

    while (nullptr != curr && curr->mData <= val)  // 末尾检测
    {
        pre = curr;                             // 不断向前循环，直到末尾或者找到不小于val的元素
        curr = curr -> next;       
    }

    newNode->next = curr;                      // 改变指针指向
    pre ->next =  newNode;
    return dummyNode.next;                     // 返回链表头节点
}

ListNode *Merge(ListNode *head1, ListNode *head2)   // 将head2合并到head1
{
    ListNode dummyNode;
    ListNode *dummy = &dummyNode;               // 临时指针
    while(nullptr != head1 && nullptr != head2)       // 循环直到末尾
    {
        if (head1->mData <= head2 ->mData)      // 类似于归并排序
        {
            dummy->next = head1;
            head1 = head1 -> next;
        }else{
            dummy->next = head2;
            head2 = head2->next;
        }
        dummy = dummy->next;
    }
    if (nullptr != head1) dummy->next = head1;
    if(nullptr!=head2) dummy->next = head2;
    return dummyNode.next;
}

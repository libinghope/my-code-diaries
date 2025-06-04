/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (64.88%)
 * Likes:    494
 * Dislikes: 0
 * Total Accepted:    54.2K
 * Total Submissions: 83.4K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //时间复杂度为nlogn首先想到用快排的思想来做了
    //但是又要求常数空间复杂度，那就只能是归并排序了,并且是自底向上而不能用递归
    //也就是把数组的归并排序修改为支持链表的就可以了
    ListNode* sortList(ListNode* head) {
         ListNode virtualHead(0);//虚拟空头指针
         virtualHead.next = head;
         auto p = head;
         int length = 0;
         while(p){
             ++length;
             p=p->next;
         }

         for(int scale =1;scale < length; scale<<=1){
             auto cur = virtualHead.next;
             auto tail = &virtualHead;
             while(cur){
                 auto left = cur;
                 auto right = cut(left,scale);//切第一个，切断前两个···
                 cur = cut(right,scale);//切断第二个，切断第三第四个···
                 tail->next=merge(left,right);//第一次处理相邻两个元素，然后2个，然后4个···
                 while(tail->next){//串上后面的链表
                     tail = tail->next;
                 }
             }
         }
         return virtualHead.next;
    }
    ListNode* merge(ListNode* left,ListNode*right){
        ListNode virtualHead(0);//虚拟空头指针
        auto p = &virtualHead;
        while(left && right){
            if(left->val < right->val){
                p->next=left;
                p = left;
                left = left->next;
            }else{
                p->next = right;
                p = right;
                right = right->next;
            }
        }
        p->next = left ? left : right;
        return virtualHead.next;
    }
    //断链操作，将链表 head 切掉前 n 个节点，并返回后半部分的链表头。
    ListNode* cut(ListNode* head,int n){
        auto p = head;
        while(--n && p){
            p=p->next;
        }
        if(!p) return NULL;
        auto next = p->next;
        p->next = NULL;//切断
        return next;
    }
};
// @lc code=end


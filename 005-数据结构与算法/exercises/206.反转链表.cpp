/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (68.03%)
 * Likes:    853
 * Dislikes: 0
 * Total Accepted:    196.2K
 * Total Submissions: 287.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
 */

// @lc code=start

 //* Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* reverseList2(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* p,q,r;
        p = head;
        q = p->next;
        p->next = nullptr;
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* tmp = reverseList(head->next);
        ListNode* p = tmp;
        while(p && p->next){p=p->next;}
        p->next = head;
        head->next = NULL;
        return tmp;
    }
    ListNode* reverseList1(ListNode* head) {
        ListNode* p = head;
        if(!p || !p->next) return head;
        ListNode* q = p->next;
        p->next = NULL;
        while(q){
            ListNode* tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }
};
// @lc code=end


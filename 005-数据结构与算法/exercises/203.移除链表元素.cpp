/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (44.53%)
 * Likes:    358
 * Dislikes: 0
 * Total Accepted:    66.1K
 * Total Submissions: 148K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        while(p && p->val==val){
            ListNode* q = p;
            p = p->next;
            delete q;
            q = NULL;
            head = p;
        }
        while(p){
            if(p->next && p->next->val == val){
                ListNode* q = p->next;
                p->next = p->next->next;
                delete q;
                q = NULL;
            }else{
                p=p->next;
            }
            
        }
        return head;
    }
};
// @lc code=end


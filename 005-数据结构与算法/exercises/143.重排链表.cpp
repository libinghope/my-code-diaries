/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (55.57%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    21.5K
 * Total Submissions: 38.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        stack<ListNode*> stack;
        ListNode* insert_pos = head;
        ListNode* rear = head;
        stack.push(rear);
        while(rear->next){
            rear = rear->next;
            stack.push(rear);
        }
        while(insert_pos!=rear && insert_pos->next!=rear){
            ListNode* tmp = insert_pos->next;
            insert_pos->next = rear;
            rear->next = tmp;
            stack.pop();
            rear = stack.top();
            rear->next=NULL;
            insert_pos = insert_pos->next->next;
        }
    }
};
// @lc code=end


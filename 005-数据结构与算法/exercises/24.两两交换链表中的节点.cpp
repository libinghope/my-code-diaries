/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (64.73%)
 * Likes:    453
 * Dislikes: 0
 * Total Accepted:    87.3K
 * Total Submissions: 134.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
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
        ListNode* swapPairs(ListNode* head) {
        ListNode* cur=head;
        ListNode* next=NULL;
        ListNode* pre=NULL;
        ListNode* ret=NULL;
        if(!head || !head->next) return head;
        while(cur && cur->next){
            if(!next && !ret) ret = cur->next;
            next = cur->next;
            cur->next = next->next;
            next->next = cur;
            if(pre)
                pre->next = next;
            pre = cur;
            if(!cur->next){
                return ret;
            }else{
                cur = cur->next;
            }
        }
        return ret;
    }
};
// @lc code=end


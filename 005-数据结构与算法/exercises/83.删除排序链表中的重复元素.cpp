/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (49.43%)
 * Likes:    274
 * Dislikes: 0
 * Total Accepted:    83.2K
 * Total Submissions: 167.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */

// @lc code=start

 //Definition for singly-linked list.
//  struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode(int x) : val(x), next(NULL) {}
//       };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode *p=head;
        while(p){
            if(p->next && p->val == p->next->val){
                ListNode *q = p->next;
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


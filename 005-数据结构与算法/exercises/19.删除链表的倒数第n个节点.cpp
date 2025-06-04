/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (37.98%)
 * Likes:    756
 * Dislikes: 0
 * Total Accepted:    145.3K
 * Total Submissions: 380.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slow_pre = head;
        if(!head->next){delete head;return NULL;}
        int num = 0;
        while(fast){
            if(num>=n){
                slow_pre = slow;
                slow = slow->next;
            }
            ++num;
            fast = fast->next;
        }
        if(slow==head){
            ListNode* tmp = head->next;
            delete head;
            return tmp;
        }
        slow_pre->next = slow->next;
        delete slow;
        slow = NULL;
        return head;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (60.30%)
 * Likes:    895
 * Dislikes: 0
 * Total Accepted:    204K
 * Total Submissions: 338.3K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
        {
            return nullptr;
        }
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (p1 || p2)
        {
            if (p1 && p2)
            {
                if (p1->val < p2->val)
                {
                    tail->next = p1;
                    p1 = p1->next;
                }
                else
                {
                    tail->next = p2;
                    p2 = p2->next;
                }
                tail = tail->next;
            }
            else if (p1 || p2)
            {
                p1 ? tail->next = p1 : tail->next = p2;
                break;
            }
        }
        ListNode *tmp = head->next;
        delete head;
        return tmp;
    }
};
// @lc code=end

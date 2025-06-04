/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.89%)
 * Likes:    4077
 * Dislikes: 0
 * Total Accepted:    367.2K
 * Total Submissions: 993.6K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start

 //* Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = NULL;
        ListNode* rear = NULL;
        while(l1 || l2 || carry != 0){
            int tmp1 = l1 ? l1->val : 0;
            int tmp2 = l2 ? l2->val : 0;
            int tmp = (tmp1 + tmp2) + carry;
            if(tmp>9) {
                carry = 1;
                tmp = tmp %10;
            }else{
                carry = 0;
            }
            if(!head) {
                head = new ListNode(tmp);
                rear = head;
            }else{
                rear->next = new ListNode(tmp);
                rear = rear->next;
            }
            l1 ? l1 = l1->next : NULL;
            l2 ? l2 = l2->next : NULL;
        }
        return head;
    }
};
// @lc code=end


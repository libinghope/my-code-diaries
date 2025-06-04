/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (56.91%)
 * Likes:    428
 * Dislikes: 0
 * Total Accepted:    46.8K
 * Total Submissions: 81.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* pre_start = NULL;
        vector<ListNode*> vec_node;
        ListNode* end = head;
 
        //反转start到end的所有节点
        ListNode* ret=NULL;
        while(true){
            vec_node.push_back(pre_start);
            for(int i=0;i<k;++i){
                if(!end){return ret;}
                vec_node.push_back(end);
                end=end->next;
            }
            if(!ret){ret = vec_node[k];}
            int j = 0;
            ListNode* cur_pre = NULL;
            for(int j=0;j<k/2;++j){
                if(!cur_pre) cur_pre = pre_start;
                swapNode(cur_pre,vec_node[j+1],vec_node[k-1-j],vec_node[k-j]);
                cur_pre = vec_node[k-j];
            }
            pre_start = vec_node[j+1];
            vec_node.clear();
        }
        
        return ret;
    }
        void swapNode(ListNode* start_pre,ListNode* start,ListNode* end_pre,ListNode* end){
        if(start_pre){
            start_pre->next=end;
        }
        end_pre->next=start;
        ListNode* tmp;
        tmp = end->next;
        end->next = start->next;
        start->next=tmp;
    }
};
// @lc code=end


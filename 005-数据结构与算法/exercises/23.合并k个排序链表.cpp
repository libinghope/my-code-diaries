/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (49.38%)
 * Likes:    545
 * Dislikes: 0
 * Total Accepted:    90.4K
 * Total Submissions: 182K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    //目前使用的是冒泡排序，速度比较慢
   ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(0==k) return NULL;
        if(1==k) return lists[0];

        ListNode* head = NULL;
        ListNode* min = NULL;
        ListNode* cur = NULL;
        while(!lists.empty()){
            min = NULL;
            for(int i=0;i<lists.size();++i){
                vector<ListNode*>::iterator it=lists.begin();
                if(!lists[i]) {
                    it += i;
                    --i;
                    lists.erase(it);
                    continue;
                }
                if(cur==lists[i]){
                    
                    //lists[i]=lists[i]->next;
                    it += i;
                    auto iter = lists.erase(it);
                    if(cur->next)
                        lists.insert(iter,cur->next);
                    if(lists.empty()){return head;}
                    
                }
                if(!min && lists[i]){
                    min = lists[i];
                    continue;
                }
                if(min && lists[i] && min->val > lists[i]->val){
                    min = lists[i];
                }
            }
            if(!min){
                return head;
            }
            if(!head){
                head = min;
            }
            if(!cur){
                cur=min;
            }else{
                cur->next=min;
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end


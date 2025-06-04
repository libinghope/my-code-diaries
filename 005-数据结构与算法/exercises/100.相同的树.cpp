/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode-cn.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (56.72%)
 * Likes:    329
 * Dislikes: 0
 * Total Accepted:    71.7K
 * Total Submissions: 126K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 示例 1:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:      1          1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * 输出: false
 * 
 * 
 */

// @lc code=start

//Definition for a binary tree node.
/*  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; */
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //前序遍历两棵树
        stack<TreeNode*> ps;
        stack<TreeNode*> qs;

        while((p && q) || (!ps.empty() && !qs.empty())){
            while(p && q){
                if(p->val != q->val){
                    return false;
                }
                ps.push(p);
                qs.push(q);
                p = p->left;
                q = q->left;
                if((q && !p)||(!q && p)){return false;}
            }
            if(!ps.empty() && !qs.empty()){
                p = ps.top();
                ps.pop();
                q = qs.top();
                qs.pop();
                p = p->right;
                q = q->right;
                if((q && !p)||(!q && p)){return false;}
            }
        }
        return p == q;
    }
};
// @lc code=end


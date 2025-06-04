/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (64.01%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 37.7K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;

        stack<TreeNode*> stack,stack1;
        if(!root) return ret;
        stack.push(root);
 
        while(!stack.empty()){
            TreeNode* right_node = stack.top();
            ret.push_back(right_node->val);
            while(!stack.empty()){
                stack1.push(stack.top());
                stack.pop();
            }
            while(!stack1.empty()){
                TreeNode* qf = stack1.top();
                if(qf->left){stack.push(qf->left);}
                if(qf->right){stack.push(qf->right);}
                stack1.pop();
            }
            
        }

        return ret;
    }
};
// @lc code=end


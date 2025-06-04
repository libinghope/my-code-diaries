/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (65.05%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    93.5K
 * Total Submissions: 143.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> stack;
        stack.push(root);

        while(!root || !stack.empty()){
            root = stack.top();
            ret.push_back(root->val);
            stack.pop();

            if(root->right) stack.push(root->right);
            if(root->left) stack.push(root->left);
            while(!stack.empty()){
                root = stack.top();
                ret.push_back(root->val);
                stack.pop();
                if(root->right) stack.push(root->right);
                if(root->left) stack.push(root->left);
            }
        }
        return ret;
    }
};
// @lc code=end


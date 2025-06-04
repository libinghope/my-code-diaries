/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.51%)
 * Likes:    435
 * Dislikes: 0
 * Total Accepted:    126.5K
 * Total Submissions: 179K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
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
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include<vector>
#include<stack>
using namespace std;
// @lc code=start

//* Definition for a binary tree node.
/*  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }; */
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>  stack;
        vector<int> dv;
        while(root || !stack.empty()){
            while(root){
                stack.push(root);
                root = root->left;
            }
            if(!stack.empty()){
                root = stack.top();
                dv.push_back(root->val);
                stack.pop();
                root = root->right;
            }
        }
        return dv;
    }
};
// @lc code=end


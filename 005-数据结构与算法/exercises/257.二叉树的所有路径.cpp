/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (62.67%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    29.5K
 * Total Submissions: 46.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 */
#include <vector>
using namespace std;
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
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
                vector<string> str_vec;
        if (!root)
        {
            return str_vec;
        }
        if (root->left)
        {
            vector<string> tmp = binaryTreePaths(root->left);
            for (int i = 0; i < tmp.size(); i++)
            {
                str_vec.push_back((to_string(root->val))+ "->" +tmp[i]);
            }
        }
        if (root->right)
        {
            vector<string> tmp = binaryTreePaths(root->right);
            for (int i = 0; i < tmp.size(); i++)
            {
                str_vec.push_back((to_string(root->val))+ "->" +tmp[i]);
            }
        }
        if(!root->left && !root->right){
            str_vec.push_back(to_string(root->val));
            return str_vec;
        }
        return str_vec;
    }
};
// @lc code=end

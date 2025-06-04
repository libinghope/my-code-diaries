/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (61.11%)
 * Likes:    438
 * Dislikes: 0
 * Total Accepted:    101.3K
 * Total Submissions: 165K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
    /*根据之前数据结构课程学到的知识，使用队列进行逐层访问
    这里题目有一个关键点，要一层一层逐层输出，分清层次
    使用队列储存一层数据，出队的同时用vector保存其子节点，
    出队完成，遍历子节点的vector，把其子节点保存到队列中，
    以此类推直到最后
    
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        
    }
};
// @lc code=end


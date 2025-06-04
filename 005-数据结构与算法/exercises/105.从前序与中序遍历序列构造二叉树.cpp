/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.49%)
 * Likes:    405
 * Dislikes: 0
 * Total Accepted:    56.6K
 * Total Submissions: 87.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    /*方法是固定的
    首先，preorder 中的第一个元素一定是树的根，
    这个根又将 inorder 序列分成了左右两棵子树 分别为left_num right_num个。
    同时得到了左右子树的节点数目，而前序遍历的存放序列是
    [根(第一个),左子树(left_num)，右子树(right_num)]
    现在我们只需要将先序遍历的数组中删除根元素，
    然后重复上面的过程处理左右两棵子树。
    */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (29.31%)
 * Likes:    474
 * Dislikes: 0
 * Total Accepted:    83.1K
 * Total Submissions: 281.6K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
    /*
    递归：一颗二叉树是搜索树的条件是，左子树和右子树都是二叉搜索树，
    还是太年轻，还需要保证右子树的所有数大于根，左子树都小于根

    二叉搜索树的中序遍历是一个递增的排序列表，搞定
    */
public:
    bool isValidBST(TreeNode* root) {
        if(root){
            isValidBST(root->left);
            if(vec.empty()) vec.push_back(root);
            else if(root->val > vec[vec.size()-1]->val){
                vec.push_back(root);
            }else{
                ret = false;
            }
            isValidBST(root->right);
        }
        return ret;
    }
private:
    vector<TreeNode*> vec;
    bool ret=true;

};
// @lc code=end


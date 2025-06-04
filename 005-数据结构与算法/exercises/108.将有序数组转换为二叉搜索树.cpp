/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (69.66%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    55.7K
 * Total Submissions: 79.8K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
// Definition for a binary tree node.
//  struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(0==nums.size()){return NULL;}
        if(nums.size()==1){
            return new TreeNode(nums[0]);
        }
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> leftArr(nums.begin(),nums.begin()+mid);
        vector<int> rightArr(nums.begin()+mid+1,nums.end());
        root->left = sortedArrayToBST(leftArr);
        root->right = sortedArrayToBST(rightArr);
        return root;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (59.07%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    40.2K
 * Total Submissions: 68.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
 
class Solution {
public:
    /*
    深度优先搜索
    */
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<int> path;
        if(!root){return ret;}
        DFS(root,path,sum);
        return ret;
    }
    void DFS(TreeNode* root,vector<int> path,int target){
        if(!root){return;}
        path.push_back(root->val);
        if(!root->left && !root->right){
            //计算路径和
            int sum = 0;
            int i = 0;
            while(i<path.size()){
                sum+=path[i];
                ++i;
            }
            if(sum==target) ret.push_back(path);
        }
        DFS(root->left,path,target);
        DFS(root->right,path,target);
    }
    private:
    vector<vector<int> >ret;
};
// @lc code=end


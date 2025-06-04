/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (39.75%)
 * Likes:    373
 * Dislikes: 0
 * Total Accepted:    32.5K
 * Total Submissions: 81.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start

//* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    /*
    图的多源路径算法
    使用弗洛伊德算法
    */

    /**
    对于任意一个节点, 如果最大和路径包含该节点, 那么只可能是两种情况:
    1. 其左右子树中所构成的和路径值较大的那个加上该节点的值后向父节点回溯构成最大路径
    2. 左右子树都在最大路径中, 加上该节点的值构成了最终的最大路径
    **/
    int maxPathSum(TreeNode* root) {
        vector<vector<int> > matrix;

    }
    vector<vector<int> > constructMatrix(TreeNode* root){
        vector<vector<int> > matrix;
        //层序遍历
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            root = queue.front();
            queue.pop();
            vector<int> row;
            if(root->left){
                row.push_back(root->val + root->left->val);
            }else{
                row.push_back(INT_MIN);
            }
            if(root->right){
                row.push_back(root->val + root->left->val);
            }else{
                row.push_back(INT_MIN);
            }
        }

        return matrix;
    }

    void floyd(int *P[], int *D[]){

    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.94%)
 * Likes:    281
 * Dislikes: 0
 * Total Accepted:    69.9K
 * Total Submissions: 98.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
//所谓后序遍历，就是对每个节点(点前节点)，先访问其左孩子，再访问右孩子，再访问自身

    //从根到左下角一一入栈，对于栈中的每个元素元素进行如下操作
    /*
    如果没有右子树，就访问当前节点(根节点),如果有，就访问右子树
    并且要切断当前节点与右子树的连接
    */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stack;

        TreeNode* cur = root;
        while(cur || !stack.empty()){
            //一直向左下角走到最后
            if(cur){//如果当前节点存在
                stack.push(cur);//入栈
                cur = cur->left;//指向左子树
            }else{//已经到左下角了
                //因为栈中是从根到左下的所有左孩子
                //所以第一次取出的节点肯定没有左孩子
                TreeNode* tmp = stack.top();
                if(!tmp->right){//没有右子树，
                    stack.pop();//就访问根节点
                    ret.push_back(tmp->val);
                }else{
                    //有右子树就拿到右子树,
                    //以当前右子树的根节点为根节点，进行如上循环操作
                    cur = tmp->right;
                    //切断与右子树的连接
                    tmp->right = nullptr;
                }
            }
        }
        return ret;
    }
};
// @lc code=end


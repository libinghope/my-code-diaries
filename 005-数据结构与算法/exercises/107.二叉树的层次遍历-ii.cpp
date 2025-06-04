/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (64.58%)
 * Likes:    203
 * Dislikes: 0
 * Total Accepted:    47.4K
 * Total Submissions: 73.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */

// @lc code=start

// Definition for a binary tree node.
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vector_int;
// void printArr(vector_int v);
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
public:
    vector<vector_int> levelOrderBottom(TreeNode *root)
    {
        vector<vector_int> dv;
        if (!root)
            return dv;
        queue<TreeNode *> q1, q2;
        stack<vector_int> s;
        q1.push(root);

        while (!q1.empty() || !q2.empty())
        {
            if (!q1.empty())
            {
                vector_int tmpv;
                while (!q1.empty())
                {
                    TreeNode *t = q1.front();
                    tmpv.push_back(t->val);
                    q1.pop();
                    if (t->left)
                        q2.push(t->left);
                    if (t->right)
                        q2.push(t->right);
                }
                s.push(tmpv);
            }

            if (!q2.empty())
            {
                vector_int tmpv;
                while (!q2.empty())
                {
                    TreeNode *t = q2.front();
                    tmpv.push_back(t->val);
                    q2.pop();
                    if (t->left)
                    {
                        q1.push(t->left);
                    }
                    if (t->right)
                    {
                        q1.push(t->right);
                    }
                }
                s.push(tmpv);
            }
        }
        while (!s.empty())
        {
            dv.push_back(s.top());
            s.pop();
        }
        return dv;
    }
};
// @lc code=end
void printArr(vector_int v){
    cout<<"[";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<",";
    }
    cout<<"]"<<endl;
}
int main(){
    TreeNode root(1);
    TreeNode n2(2);
    TreeNode n3(3);
    root.left=&n2;
    root.right=&n3;
    Solution s;
    vector<vector_int> vv = s.levelOrderBottom(&root);
    cout<<"---------------------------------"<<endl;
    cout<<"vv.size()="<<vv.size()<<endl;
    for(int k=0;k<vv.size();k++){
        printArr(vv[k]);
    }
    return 0;
}

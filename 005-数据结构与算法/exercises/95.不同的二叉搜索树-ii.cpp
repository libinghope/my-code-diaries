/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (61.96%)
 * Likes:    322
 * Dislikes: 0
 * Total Accepted:    24.4K
 * Total Submissions: 39.2K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start

//* Definition for a binary tree node.
//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//   };
/*
  * 若根节点为i，则左子树的节点为[1,...,i-1]，
  * 右子树的节点为[i+1,...,n][i+1,...,n]。
  * 可递归的构建二叉搜索树。
  */
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> dv;
        if (n == 0)
        {
            return dv;
        }
        return buildTrees(1, n);
    }

    vector<TreeNode *> buildTrees(int start, int end)
    {
        vector<TreeNode *> res;
        if (start > end)
        {
            res.push_back(NULL);
            return res;
        }
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> lefts = buildTrees(start, i - 1);
            vector<TreeNode *> rights = buildTrees(i + 1, end);
            for (int j = 0; j < (int)lefts.size(); j++)
            {
                for (int k = 0; k < (int)rights.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

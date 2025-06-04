/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (65.12%)
 * Likes:    437
 * Dislikes: 0
 * Total Accepted:    35.7K
 * Total Submissions: 54.8K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> t(n + 1, 0);
        t[0] = t[1] = 1;
        int i, j;
        for (i = 2; i <= n; ++i)
        {
            for (j = 1; j <= i / 2; ++j)
                t[i] += t[j - 1] * t[i - j];
            t[i] *= 2;
            if (i % 2)
                t[i] += t[i / 2] * t[i / 2]; //Plus the middle 'root' trees.
        }
        return t[n];
    }
    //递归报错，好像是严重超时
    /* 非递归方法分析
    设f(n) 为n个结点时二插排序树的个数,则有
    1为根节点时候 左子树有0个结点，有1种， f(0)=1 右子树结点数 n-1,即f(n-1)种
    2为根节点时候 左子树有1,    1个节点，有1种， f(1)=1 右子树结点数 n-2，即f(n-2)
    3为根节点时候 左子树有1,2   2个节点，有2种即 f(2)=2 右子树结点数 n-3, 即f(n-3)
    ···
    n为根节点时候，左子树有n-1个结点，f(n-1),     右子树结点数为0   即f(0)=1

    总结f(n) = f(0)*f(n-1)+f(1)*f(n-2)+···+f(n-1)*f(0)
    0,1
    
   int numTrees1(int n){
       if(n<=1) return 1;

       if(0==n%2){
           //2(f(0)*f(n-1)+f(1)*f(n-2)+···+f(n/2-1)*f(n/2))
       }else{
           //2(f(0)*f(n-1)+f(1)*f(n-2)+···+f(n/2)*f(n/2))-f(n/2)f(n/2)
       }
   }
    int numTrees2(int n){
        if(0==n) return 1;
        if(n==1) return 1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=numTrees2(i)*numTrees2(n-i-1);
        }
        
        return sum;
    }

    int calcNum(int start, int end)
    {
        if (start >= end)
            return 1;
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            int left = calcNum(start, i - 1);
            int right = calcNum(i + 1, end);
            num += left * right;
        }
        return num;
    }*/
};
// @lc code=end

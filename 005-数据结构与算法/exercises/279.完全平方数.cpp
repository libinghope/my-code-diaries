/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (55.41%)
 * Likes:    398
 * Dislikes: 0
 * Total Accepted:    53.7K
 * Total Submissions: 96.4K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

// @lc code=start
class Solution {
public:
/*
任何一个正整数都可以表示成不超过四个整数的平方之和。 
推论：满足四数平方和定理的数n（四个整数的情况），必定满足 n=4^a(8b+7)

这道题考察的应该是动态规划算法
最主要的是找出状态转化方程
首先初始化dp[i] = i; // 最坏的情况就是每次+1，就是1的平方+1的平方...一直加下去
 dp[i] = Math.min(dp[i], dp[i - j * j] + 1); // 动态转移方程
*/
    int numSquares(int n) {
        int* dp = new int[n + 1]; // 默认初始化值都为0
        for (int i = 1; i <= n; i++) {
            dp[i] = i; // 最坏的情况就是每次+1
            for (int j = 1; i - j * j >= 0; j++) { 
                dp[i] = min(dp[i], dp[i - j * j] + 1); // 动态转移方程
            }
        }
        return dp[n];
    }
    int min(int x,int y){
        return x< y? x: y;
    }
};
// @lc code=end


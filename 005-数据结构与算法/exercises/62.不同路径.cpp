/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (59.34%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    89.3K
 * Total Submissions: 149.4K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10 ^ 9
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*典型的动态规划问题,动态规划3步走

    1、定义数组 dp[i][j],含义是从左上角(0,0)到坐标(i,j)的路径数
    2、找到递推公式 
        很明显的dp[0][0]=1
        当i=0时候，dp[0][j] = dp[0][j-1]=1(意思是一直向右)
        当j=0时候，dp[i][0]=dp[i-1][0]=1(意思是一直向下)
        其他情况，dp[i][j] = dp[i-1][j]+dp[i][j-1]

        dp[m-1][n-1]就是最后的结果
    */
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector(n,-1));
        dp[0][0] = 0;
        for(int j=0;j<n;++j) dp[0][j] = 1;
        for(int i=0;i<m;++i) dp[i][0] = 1;

        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end


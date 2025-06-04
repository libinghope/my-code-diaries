/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (64.85%)
 * Likes:    429
 * Dislikes: 0
 * Total Accepted:    73.9K
 * Total Submissions: 113.4K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*很明显只能向下或者向右走
    依然是动态规划的问题，三部走
    1、定义数组dp[i][j],意思是从(0,0)到(i,j)的最短路径和
    2、找到递推公式
        i=0,j>0时候，dp[0][j]=dp[0][j-1]+nums[i][j]
        当j=0,i>0时候，dp[i][0]=dp[i-1][0]+nums[i][j]
        其他情况dp[i][j]=min(dp[i-1][j],dp[i][j-1])+nums[i][j]

    */
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m,vector<int>(n,-1));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;++i) dp[i][0] = dp[i-1][0]+grid[i][0];
        for(int j=1;j<n;++j) dp[0][j] = dp[0][j-1]+grid[0][j];
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
    int min(int a,int b){
        return a<b ? a: b; 
    }
};
// @lc code=end


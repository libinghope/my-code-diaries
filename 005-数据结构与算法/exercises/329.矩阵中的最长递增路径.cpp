/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (40.01%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 30.1K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个整数矩阵，找出最长递增路径的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
 * 
 * 示例 1:
 * 
 * 输入: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2:
 * 
 * 输入: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 */

// @lc code=start
typedef vector<vector<int>> int_matrix;
class Solution {
public:
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int x, int y){
        
        if(memo[x][y]!=-1) return memo[x][y];
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int ans = 1;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                int tx = x+dx[i], ty = y+dy[i];
                if(tx<memo.size() && tx>=0 && ty>=0 && ty<memo[0].size() && matrix[x][y]>matrix[tx][ty]){
                    ans = max(ans, 1+dfs(matrix, memo, tx, ty));
                }
            }
        }
        return memo[x][y]=ans;
    }
    int longestIncreasingPath1(vector<vector<int>>& matrix) {
        
        // 方法一：给定初始节点，dfs搜索
        int m = matrix.size(); if(m==0) return 0;
        int n = matrix[0].size(); if(n==0) return 0;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int ans = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, dfs(matrix, memo, i, j));
            }
        }
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max_len = 1;
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        vector<vector<int> >dp(m,vector<int>(n,-1));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int m = dfs(matrix,dp,i,j);
                //int m = DFS(matrix,dp,i,j);
                max_len = max_len > m ? max_len : m;
            }
        }
        return max_len;
    }
    int DFS(vector<vector<int>> matrix,vector<vector<int> >&dp,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];

        int x,y,z,w;
        int max = 0;
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]){
            x = DFS(matrix,dp,i+1,j);
            max = max > x ? max : x;
        }else x = 0;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            y = DFS(matrix,dp,i-1,j);
             max = max > y ? max : y;
        }else y=0;
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]){
            z = DFS(matrix,dp,i,j+1);
             max = max > z ? max : z;
        }else z=0;
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            w = DFS(matrix,dp,i,j-1);
             max = max > w ? max : w;
        }else w = 0;
        dp[i][j] = max + 1;
        return dp[i][j];

    }
    int max1(int x,int y,int z,int w){
        int m = x;
        if(y>m) m = y;
        if(z>m) m = z;
        if(w>m) m = w;
        return m;
    }
    int max(int x, int y){
        return x>y ? x:y;
    }
};
// @lc code=end


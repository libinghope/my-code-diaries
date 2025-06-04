/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (47.97%)
 * Likes:    467
 * Dislikes: 0
 * Total Accepted:    77.5K
 * Total Submissions: 161.4K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*BFS*/
     int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int num = 0;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]!='0' && !visited[i][j]){
                    ++num;
                    BFS(i,j,visited,grid);
                }
            }
        }
        return num;
    }
    void BFS(int m,int n,vector<vector<bool>> &visited,vector<vector<char>>& grid){
        visited[m][n] = true;
        //分别对上下左右进行BFS
        //上
        if(m-1>=0 && grid[m-1][n]!='0' && !visited[m-1][n]){
            BFS(m-1,n,visited,grid);
        }
        //下
        if(m+1<grid.size() && grid[m+1][n]!='0' && !visited[m+1][n]){
            BFS(m+1,n,visited,grid);
        }
        //左
        if(n-1>=0 && grid[m][n-1]!='0' && !visited[m][n-1]){
            BFS(m,n-1,visited,grid);
        }
        //右
        if(n+1<grid[0].size() && grid[m][n+1]!='0' && !visited[m][n+1]){
            BFS(m,n+1,visited,grid);
        }
    }
};
// @lc code=end


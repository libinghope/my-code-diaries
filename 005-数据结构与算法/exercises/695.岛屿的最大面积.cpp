/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 *
 * https://leetcode-cn.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (63.18%)
 * Likes:    257
 * Dislikes: 0
 * Total Accepted:    41.3K
 * Total Submissions: 65.3K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
 * 
 * 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被
 * 0（代表水）包围着。
 * 
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
 * 
 * 
 * 
 * 示例 1:
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * 
 * 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
 * 
 * 示例 2:
 * 
 * [[0,0,0,0,0,0,0,0]]
 * 
 * 对于上面这个给定的矩阵, 返回 0。
 * 
 * 
 * 
 * 注意: 给定的矩阵grid 的长度和宽度都不超过 50。
 * 
 */

// @lc code=start
class Solution {
public:
    //DFS算法 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        max = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,0));

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                int cur_area = 0;
                DFS(i,j,cur_area,grid,visited);
                max = cur_area > max ? cur_area : max;
            }
        }
        return max;
    }
    void DFS(int i,int j,int &cur_size,vector<vector<int>>& grid,vector<vector<int>>& visited){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || !grid[i][j] || visited[i][j]) return;
        visited[i][j] = 1;//设置访问标记
        ++cur_size;
        //访问上下左右
        DFS(i-1,j,cur_size,grid,visited);
        DFS(i+1,j,cur_size,grid,visited);
        DFS(i,j-1,cur_size,grid,visited);
        DFS(i,j+1,cur_size,grid,visited);
    }
private:
    int max;
};
// @lc code=end


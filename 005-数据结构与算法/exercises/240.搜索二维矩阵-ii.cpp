/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (39.92%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    52.1K
 * Total Submissions: 130.2K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
 * 
 * 
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * 
 * 
 * 示例:
 * 
 * 现有矩阵 matrix 如下：
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * 给定 target = 5，返回 true。
 * 
 * 给定 target = 20，返回 false。
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(matrix[0][0]> target || matrix[rows-1][cols-1]<target) return false;

        int left = 0;
        int bottom = rows-1;

        while(left< cols && bottom>-1){
            if(matrix[bottom][left] == target){
                return true;
            }
            else if(matrix[bottom][left] > target){
                //左下角大于target，排除当前最后一行
                --bottom;
            }else if(matrix[bottom][left] < target){
                //左下角小于target,排除当前第一列
                ++left;
            }
        }
        return false;
    }

};
// @lc code=end


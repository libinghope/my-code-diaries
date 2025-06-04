/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (63.90%)
 * Likes:    357
 * Dislikes: 0
 * Total Accepted:    50.2K
 * Total Submissions: 78.1K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    深度优先遍历，记录每行使用的数据的位置 cur_pos
    就能保证空间复杂度是n了

    动态规划，dp[i][j] 意思是包括triangle[i][j]的最小和
    */
    int minimumTotal(vector<vector<int>>& triangle) {
        //int* cur_pos = new int[triangle.size()]{0};
        vector<int> cur_pos(triangle.size(),0);
        int min = INT_MAX;
        int sum = 0;

        return min;
    }
};
// @lc code=end


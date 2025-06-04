/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (49.26%)
 * Likes:    1072
 * Dislikes: 0
 * Total Accepted:    78.2K
 * Total Submissions: 156.1K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    一般做法，计算每个元素对应的雨水面积，累加之
    每个元素对应的雨水面积的计算方法，
        1、左边的最大值，max_left
        2、右边的最大值，max_right
        min(max_left,max_right) - cur
    */
    int trap(vector<int>& height) {
        
    }
};
// @lc code=end


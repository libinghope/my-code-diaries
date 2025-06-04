/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (39.15%)
 * Likes:    518
 * Dislikes: 0
 * Total Accepted:    38.2K
 * Total Submissions: 97.3K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */
#include<stack>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    这道题的关键在于，理解 以heights[i]为高度的矩形的最大面积取决于
    i，左边第一个比heights[i]低的矩形heights[left_low]以及右侧出现
    的第一个比heights[i]低的矩形heights[right_low]

    这种题目可以使用典型的单调栈来解决
    */
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        stack.push(-1);
        int max_area = 0;
        for(int i=0;i<heights.size();++i){
            while(stack.top()!= -1 && heights[i] < heights[stack.top()]){
                int cur_height = heights[stack.top()];
                stack.pop();
                int cur_area = cur_height * (i-stack.top()-1);
                max_area = max_area>cur_area ? max_area : cur_area;
            }
            stack.push(i);
        }
        while(stack.top() != -1){
            int cur_height = heights[stack.top()];
            stack.pop();
            int cur_area = cur_height * (heights.size()-stack.top()-1);
            max_area = max_area>cur_area ? max_area : cur_area;
        }
        return max_area;
    }
};
// @lc code=end


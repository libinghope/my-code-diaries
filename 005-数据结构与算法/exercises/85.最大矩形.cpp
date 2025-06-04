/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (44.80%)
 * Likes:    373
 * Dislikes: 0
 * Total Accepted:    23.4K
 * Total Submissions: 51.8K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    这道题可以转化成上一道题的模式

    对每一行的下边沿作为x轴，第一列作为y轴，计算该行的maxRec
    
    针对每一行中的每一个元素的高度等于，从该行向上找到第一个不为
    1的位置，就是高度
    */
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        vector<int> heights;
        int rows = matrix.size();
        int max = 0;
        for(int r=0;r<rows;++r){
            heights.clear();
            for(int i=0;i<matrix[0].size();++i){
                if(matrix[r][i]=='0'){
                    heights.push_back(0);
                }else{
                    //等于1的情况，向上计算总共多少个1
                    int row = r-1;
                    int h = 1;
                    while(row > -1 && matrix[row][i]=='1'){
                        --row;
                        ++h;
                    }
                    heights.push_back(h);
                }
            }
            int cur_large = largestRectangleArea(heights);
            max = max>cur_large ? max : cur_large;
        }
        return max;
    }

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


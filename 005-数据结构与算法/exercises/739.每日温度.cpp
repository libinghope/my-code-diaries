/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (60.03%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    44.5K
 * Total Submissions: 73.6K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    第一感觉是这道题太简单了

    但是作为一道算法题，肯定不能使用暴力搜索的方法

    使用递减栈来完成O(n)时间复杂度的计算
    */
    vector<int> dailyTemperatures(vector<int>& T) {

    }
};
// @lc code=end


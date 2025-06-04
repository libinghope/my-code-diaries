/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (35.89%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    27.9K
 * Total Submissions: 77.5K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    每次找开头第一个数最大的那个数字放在左边，如果都一样大，就比较第二位
    */
    string largestNumber(vector<int>& nums) {

    }
    //关键是要理解下面这个函数
    int compare(string a, string b) {
            String order1 = a + b;
            String order2 = b + a;
           return order2.compareTo(order1);
        }
};
// @lc code=end


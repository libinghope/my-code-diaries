/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (43.46%)
 * Likes:    440
 * Dislikes: 0
 * Total Accepted:    131.3K
 * Total Submissions: 301.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        
        for(int i=digits.size()-1; i >= 0 && carry; i--) {
            carry = (++digits[i]%=10) == 0;
        }

        if(carry) {
            digits.insert(digits.begin(), 1);
        }
    
        return digits;
    }
    vector<int> plusOne1(vector<int> &digits)
    {
        int t = (digits.size() - 1);

        while (digits[t] == 9 && t > -1)
        {
            digits[t] = 0;
            t--;
        }
        if (t == -1)
        {
            digits.insert(digits.begin(),1);
            for(int i=1;i<digits.size()-1;i++){
                digits[i] = 0;
            }
        }
        else
        {
            digits[t] += 1;
        }
        return digits;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (49.78%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    30.3K
 * Total Submissions: 61K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string sum = "";
        int carry = 0;
        while(len1!=0 || len2!=0 || carry){
            int l1 = len1>0 ? num1[--len1] - '0' : 0;
            int l2 = len2>0 ? num2[--len2] - '0' : 0;
            int cur = 0;
            if(l1+l2+carry>9){
                cur = l1+l2+carry -10;
                carry = 1;
            }else{
                cur = l1+l2+carry;
                carry = 0;
            }
            sum = to_string(cur)  + sum;
        }

        return sum;

    }
};
// @lc code=end


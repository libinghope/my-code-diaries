/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.20%)
 * Likes:    324
 * Dislikes: 0
 * Total Accepted:    69.8K
 * Total Submissions: 133.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ret = "";
        while (i >= 0 || j >= 0 || carry != 0)
        {
            if (i >= 0)
            {
                carry += a[i] == '0' ? 0 : 1;
                i--;
            }
            if (j >= 0)
            {
                carry += b[j] == '0' ? 0 : 1;
                j--;
            }
            ret = ((carry % 2) == 0 ? "0" : "1") + ret;
            carry /= 2;
        }
        return ret;
    }

    string addBinary1(string a, string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        long sum = 0;
        string bstrsum = "";
        int power = 1;
        while (i > -1 || j > -1)
        {
            if (i > -1)
            {
                int itmp = a[i] == '0' ? 0 : 1;
                sum += itmp * power;
                i--;
            }
            if (j > -1)
            {
                int jtmp = b[j] == '0' ? 0 : 1;
                sum += jtmp * power;
                j--;
            }
            power *= 2;
        }
        if (sum == 0)
        {
            return "0";
        }
        while (sum != 0)
        {
            int tmp = sum % 2;
            string strtmp = "";
            tmp == 0 ? strtmp = "0" : strtmp = "1";
            bstrsum = strtmp + bstrsum;
            sum /= 2;
        }
        return bstrsum;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    return 0;
}

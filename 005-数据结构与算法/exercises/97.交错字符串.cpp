/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 *
 * https://leetcode-cn.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (38.96%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 30.4K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出: false
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    是否存在，s2插入s1的某个位置或者s1插入s2的某个位置可以变成s3
    直观想法是错的

    动态规划,dp[i][j]表示s1的前i个字符，s2的前j个字符是否是s3前i+j个字符
    的交错字符串
    dp[0][0] 肯定为true
    关键是如何得到递推公式
    二维dp数组一般先考虑 第0行和第0列 很简单不再赘述

    关键是剩余的 dp[i]d[j]如何填充

    dp[i][j]=(dp[i][j-1] and s2[j-1]==s3[i+j-1]) or (dp[i-1][j] and s1[i-1]==s3[i+j-1])
    */
    bool isInterleave(string s1, string s2, string s3) {
        
    }
};
// @lc code=end


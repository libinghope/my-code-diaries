/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode-cn.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (47.18%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 24.1K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
 * 
 * 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE"
 * 的一个子序列，而 "AEC" 不是）
 * 
 * 示例 1:
 * 
 * 输入: S = "rabbbit", T = "rabbit"
 * 输出: 3
 * 解释:
 * 
 * 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * 示例 2:
 * 
 * 输入: S = "babgbag", T = "bag"
 * 输出: 5
 * 解释:
 * 
 * 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    一开始最直观的想法dp[i]表示s(0~i)中t出现的次数
    i<t.length,tp[i]=0
    i=t.length,if s(0~i)==t，则dp[i]=1 else dp[i]=0
    i>t.length,如果 s[i]==t[len-1],dp[i]=dp[i-1]+1
               否则 dp[i] = dp[i-1]
    关键如何得到dp[t.length+1]
               


    这种类型的题不用想就是动态规划
    三部走 
    1、定义数组,dp[i][j]表示t[0-j]在s[0-i]中出现的次数
    2、找递推公式
        dp[0][0] = 
        若果i=0,j>0, dp[0][j]=0
        如果i>0,j=0, dp[i][0]=1
        如果i>0&&j>0
            如果i<j,dp[i][j]=0
            如果i=j
                如果 s.substr(0，i)==t.substr(0,j) dp[i][j]=1
                否则 dp[i][j]=0
            如果i>j
            if(t.charAt(i-1) == s.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }else {
                    dp[i][j] = dp[i][j-1];
            }

    */
    int numDistinct(string s, string t) {
        
    }
};
// @lc code=end


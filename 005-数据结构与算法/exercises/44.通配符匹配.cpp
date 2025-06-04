/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode-cn.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (26.88%)
 * Likes:    302
 * Dislikes: 0
 * Total Accepted:    24.9K
 * Total Submissions: 91.2K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输入: false
 * 
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    动态规划解法三步走：核心是将复杂问题转化为一系列简单的问题
    第一步，定义dp[i][j]为字符串s的前i个元素与字符串p的前j个元素是否匹配
    第二步，找到递推公式(状态转移方程)
    第三步，判断临界条件

    难点就在于如何找到递推公式
    dp初始化为false,其中
    dp[0][0] = true; s,p都为空则匹配成功
    dp[i][j] 若j=0,即p为空的情况，i=[1~len(s)-1]必定为false
    dp[i][j] 若i=0,即s为空的情况，j=[1~len(p)-1]只有p和p前面的字符全部为*时才为true

    dp[len(s)][len(p)]就是我们要求的结果
    关键就是如何把剩下的数组填充完，分情况
    对于dp[i][j]
    1、当s[i]==p[j] 或者 p[j]=='?' dp[i][j]的值取决于dp[i-1][j-1]
    2、当p[j]== '*'时候，p[j]要么代表一个字母，要么是空字符串,所以又分两种情况
        dp[i][j-1](p[j]代表空字符串) || dp[i-1][j](p[j]代表字母) 一个满足即为true
    3、其他情况，dp[i][j]为false，不用考虑，因为dp初始化为全false
    */
    bool isMatch(string s, string p) {
        int lens=s.size();
        int lenp=p.size();
        vector<vector<bool> > dp(lens+1,vector(lenp+1,false));
        for(int i=0;i<=lens;++i){
            for(int j=0;j<=lenp;++j){
                if(i==0 && j==0) dp[i][j] = true;
                else if(j==0 && i>0) dp[i][j] = false;
                else if(i==0 && j>0) dp[i][j] = p[j-1]=='*' ? dp[i][j-1] : false;
                else if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        return dp[lens][lenp];
    }
};
// @lc code=end


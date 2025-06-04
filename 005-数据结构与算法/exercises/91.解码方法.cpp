/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.22%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 177.8K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*读到题目的第一感觉是动态规划
    动态规划三步走
    1、定义数组dp[i],表示s的前i个字符组成的字符串的解码方法总数
    2、找出递推公式
        dp[1]=1
        dp[2]=2
        如果字符串"s[0]s[1]”对应的数字大于26 dp[2]=1
        dp[i]=dp[i-1]+dp[i-2]
        需要注意的是，末位是0 只能和前面一个字符组合(10或20)
    */
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        if(s.length()==1) return 1;
        vector<int> dp(s.length(),0);
        dp[0] = 1;

        if(s[1]=='0'){
            if('0'<s[0] && s[0]<'3') dp[1]=1;
            else return dp[1] = 0;
        }else{
            if((s[0]=='1' && s[1]!='0') || (s[0]=='2' && '0'<s[1] && s[1]<'7')){
                dp[1] = 2;
            }else{
                dp[1] = 1;
            }
        }
        for(int i=2;i<s.size();++i){
            if(s[i]=='0'){
                if('0'<s[i-1] && s[i-1]<'3'){
                    dp[i] = dp[i-2];
                }else{
                    dp[i] = 0;
                }
            }else if('0'<s[i-1] && s[i-1]<'3' && '0'<s[i] && s[i]< '7'){
                dp[i] = dp[i-1] + dp[i-2];
            }else if(s[i-1]=='1' && s[i]>= '7'){
                dp[i] = dp[i-1] + dp[i-2];
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[s.length()-1];
    }
};
// @lc code=end


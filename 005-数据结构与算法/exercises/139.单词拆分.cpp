/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (44.40%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    47.7K
 * Total Submissions: 107.3K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*第一感觉是用hashtable存储所有的拆分结构
    然后一个个试探
    果然第一感觉极少有对的情况

    使用动态规划dp[i]表示s的前i个字符是否可以拆分成字典中的单词
    dp[i] = dp[j] && m.find(s.substr(j, i-j)) != m.end()
    可以理解为，前0~j为true的情况下，如果后面的字符串也在字典中
    就返回true
    */
    bool wordBreak(string s, vector<string>& wordDict) {

    }
};
// @lc code=end


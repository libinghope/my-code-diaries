/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.31%)
 * Likes:    3348
 * Dislikes: 0
 * Total Accepted:    401.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> umap1;
        int last_len = 0;
        int cur_len = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (umap1.count(s[i]) || i == s.size() - 1) {
                if(umap1.count(s[i]) && umap1[s[i]] >= start){
                    cur_len = i - start;
                    start = umap1[s[i]] + 1;
                }else{
                    if(i == s.size()-1)
                        cur_len = i - start +1;
                }
                if (cur_len > last_len) {
                    last_len = cur_len;
                }
            }
            umap1[s[i]] = i;
        }

        return last_len;
    }
};
// @lc code=end

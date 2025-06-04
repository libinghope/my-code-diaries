/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.54%)
 * Likes:    827
 * Dislikes: 0
 * Total Accepted:    91.3K
 * Total Submissions: 123.9K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> vec_str;
    vector<string> generateParenthesis(int n) {
        string str = "";
        backTrack(str,0,0,n);
        return vec_str;
    }
    void backTrack(string cur_str,int open,int close,int n){
        if(cur_str.length()==n*2){
            vec_str.push_back(cur_str);
        }
        if(open<n){
             backTrack(cur_str+"(", open+1, close, n);
        }
        if(close<open){
            backTrack(cur_str+")", open, close+1, n);
        }
    }
};
// @lc code=end


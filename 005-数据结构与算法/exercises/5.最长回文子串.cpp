/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.90%)
 * Likes:    1916
 * Dislikes: 0
 * Total Accepted:    217.4K
 * Total Submissions: 746.4K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.length();
        if(len < 2)return s;
        string longeststr(&s[0],1);
        int left_pos = 0;
        int right_pos = 0;
        bool flag = false;
        for(int i=1;i<s.length();i++){
            if(s[i-1] == s[i] && !flag){
                left_pos = i-1;
                right_pos = i;
                flag = true;
            }else{
                left_pos = i-1;
                right_pos = i+1;
                flag = false;
            }

            while(-1< left_pos && right_pos < len && s[left_pos] == s[right_pos]){
                left_pos--;
                right_pos++;
            }
            //if(right_pos==len-1) return longeststr;//不可能更长了
            string str = "";
            if(left_pos>=0 && right_pos <= len-1){//不到头不等了
                
                str = s.substr(left_pos+1, right_pos-left_pos-1);
            }else{//到头了
                if(left_pos <= -1 || right_pos >= len -1){
                    left_pos++;
                    right_pos--;//此时必定相等
                }
                str = s.substr(left_pos, right_pos-left_pos+1);
            }
            if(longeststr.length()<str.length()) longeststr = str;
            if(flag) i--;
        }

        return longeststr;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.53%)
 * Likes:    911
 * Dislikes: 0
 * Total Accepted:    205K
 * Total Submissions: 561K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=0){return "";}
        if(strs.size() == 1){return strs[0];}
        int i = 0;
        int j = 0;
        int k = 0;
        while (j<(strs.size()-1))
        {
            while(i<strs[j].size() && i<strs[j+1].size() && 
            strs[j].at(i) == strs[j+1].at(i) && (k==0 || i < k)){
                i++;
            }
            if(0==i){return "";}
            k = i;
            i = 0;
            j++;
        }
        return strs[0].substr(0,k);
        
    }
};
// @lc code=end


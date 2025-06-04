/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (42.24%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    19.7K
 * Total Submissions: 46.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> umap1;
        unordered_map<string,char> umap2;
        vector<string>vs = split(str);
        if(pattern.size() != vs.size()) return false;
        for(int i=0;i<pattern.size();i++){
            if(!umap1.count(pattern[i]) && !umap2.count(vs[i])){
                umap1[pattern[i]] =vs[i];
                umap2[vs[i]] =pattern[i];
            }else{
                if(!(umap1.count(pattern[i]) && umap2.count(vs[i])
            && umap1[pattern[i]] == vs[i] && umap2[vs[i]] == pattern[i])){
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> split(string str){
        vector<string> v;
        int start = 0;
        int end = 0;
        for(int i=0;i<str.size();i++){
            if(str[i] == ' ' || i==str.size()-1){
                if(i==str.size()-1) i++;
                v.push_back(str.substr(start,i - start));
                start = i+1;
            }
            
        }
        return v;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (29.68%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 93.6K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = s.length();
        int num = words.size();
        vector<int> vec_ret;
        if(len<=0 || num<=0)return vec_ret;
        int word_len = words[0].length();
        int total_len = num * word_len;
        if(len<total_len) return vec_ret;
        unordered_map<string,int> words_map,words_map2;
        for(string word : words){
            words_map[word] = words_map[word] + 1;
        }
        //滑动窗口，如果找到其中一个单词，就每次向右移动word_len的距离
        for(int i=0;i<len;++i){
            string cur_word = s.substr(i,word_len);
            if(words_map.count(cur_word)){
                words_map2[cur_word] = 1;
                //找到第一个单词
                string full_str = s.substr(i,total_len);
                if(full_str.length()<total_len) return vec_ret;
                for(int k=word_len;k<full_str.length();k+=word_len){
                    cur_word = full_str.substr(k,word_len);
                    if(words_map.count(cur_word)==0) {
                        words_map2.clear();
                        break;
                    }else{
                        words_map2[cur_word] = words_map2[cur_word]+1;
                        if(words_map2[cur_word]>words_map[cur_word]){
                            words_map2.clear();
                            break;
                        }
                    }
                }
                //出了for循环，
                if(words_map.size() == words_map2.size()) {
                    unordered_map<string,int>::iterator iter=words_map.begin();
                    bool flag = true;
                    for(; iter != words_map.end(); iter++){
                        if(words_map2[iter->first]!=iter->second){
                            flag = false;
                            break;
                        }
                    }
                    if(flag) vec_ret.push_back(i);
                }
                words_map2.clear();
            }
        }
        return vec_ret;
    }
};
// @lc code=end


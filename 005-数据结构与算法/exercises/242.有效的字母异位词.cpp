/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (58.84%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    84K
 * Total Submissions: 142.4K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        //const int CHAR_NUM = 26;
        vector<int> sNum(26,0);
        vector<int> tNum(26,0);

        if (s.size() != t.size())
        {
            return false;
        }
        //两个单词长度相等,遍历两个数组
        for (int j = 0; j < s.size(); j++)
        {
            sNum[int(s[j])%26]++;
            tNum[int(t[j])%26]++;
        }
        //比较字符出现的次数是否相等
        for (int k = 0; k < 26; k++)
        {
            if (sNum[k] != tNum[k])
                return false;
        }
        return true;
    }
};
// @lc code=end

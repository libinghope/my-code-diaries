/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.67%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    75.9K
 * Total Submissions: 231.5K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ')
            tail--;
        while (tail >= 0 && s[tail] != ' ')
        {
            len++;
            tail--;
        }
        return len;
    }
    int lengthOfLastWord1(string s)
    {
        int i = 0;
        int last_space_pos = -1;
        int last_letter_pos = 0;
        for (; i < s.size() - 1; i++)
        {
            if (s[i] == ' ' && s[i + 1] != ' ')
            {
                last_space_pos = i;
            }
            if (s[i] != ' ')
                last_letter_pos = i;
        }
        if (s[s.size() - 1] != ' ')
            last_letter_pos = s.size() - 1;

        return last_letter_pos - last_space_pos;
    }
};
// @lc code=end

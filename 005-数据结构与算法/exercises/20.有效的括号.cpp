/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (41.10%)
 * Likes:    1438
 * Dislikes: 0
 * Total Accepted:    225.6K
 * Total Submissions: 548.8K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_c;
        if(s.empty()){return true;}
        stack_c.push(s.at(0));
        for(int i=1;i<s.size();i++){
            if(!stack_c.empty()&&((stack_c.top()=='{' && s.at(i)=='}') ||
            (stack_c.top()=='(' && s.at(i)==')') ||
            (stack_c.top()=='[' && s.at(i)==']'))){
                stack_c.pop();
            }else{
                stack_c.push(s.at(i));
            }
        }
        return stack_c.empty();
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (47.06%)
 * Likes:    615
 * Dislikes: 0
 * Total Accepted:    110.5K
 * Total Submissions: 233.9K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
    int len = s.length();
    if(len < 2 || numRows == 1) return s;
    string vecStr = "";
    int pos1 = 0;
    int posPre = 0;
    for(int i=0;i<numRows;i++){
        pos1 = i;
        while(pos1 < len){
            vecStr += s[pos1];
            int tmp = pos1;
            pos1 += (2*numRows -2);
            if(posPre !=0 && pos1-posPre != tmp && pos1 - posPre < len){
                vecStr += s[pos1-posPre];
            }
        }
        posPre+=2;
    }
    return vecStr;
    }
};
// @lc code=end


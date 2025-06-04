/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (37.00%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 59.1K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        unordered_map<int, char> umap;
        for(int i=1;i<27;i++){
            umap[i] = 'A' + i - 1;
        }
        umap[0] = 'Z';
        //把n转化成26进制
        string s = "";
        while(n){
            s = umap[(n % 26)] + s;
            n = (n-1)/26;
        }
        return s;
    }
};
// @lc code=end


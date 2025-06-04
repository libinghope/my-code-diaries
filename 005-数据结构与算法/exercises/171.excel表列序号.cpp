/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (66.73%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    34.4K
 * Total Submissions: 51.5K
 * Testcase Example:  '"A"'
 *
 * 给定一个Excel表格中的列名称，返回其相应的列序号。
 * 
 * 例如，
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: "A"
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: "AB"
 * 输出: 28
 * 
 * 
 * 示例 3:
 * 
 * 输入: "ZY"
 * 输出: 701
 * 
 * 致谢：
 * 特别感谢 @ts 添加此问题并创建所有测试用例。
 * 
 */
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        unordered_map<char,int> umap;
        for(int i=0;i<26;i++){
            umap['A'+i] = i + 1;
        }
        long long sum = 0;
        long long tmp = 1;
        for(int j=s.size()-1;j>=0;j--){
            sum += umap[s[j]] * tmp;
            tmp *= 26;
        }
        return sum;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.82%)
 * Likes:    634
 * Dislikes: 0
 * Total Accepted:    94.4K
 * Total Submissions: 178K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
     vector<string> v;
        if(digits.length()<1){return v;}
        vector<string> vec_data;//{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vec_data.push_back("abc");
        vec_data.push_back("def");
        vec_data.push_back("ghi");
        vec_data.push_back("jkl");
        vec_data.push_back("mno");
        vec_data.push_back("pqrs");
        vec_data.push_back("tuv");
        vec_data.push_back("wxyz");

        int digits_len = digits.length();
        int row = 1;
        const int col = digits_len;

        for(int l =0;l<digits_len;++l){
            row *= vec_data[digits[l]-'2'].length();
        }

        //int (*resArr)[col] = new int[row][col];
        vector<string> res(row,string(col, ' '));
        int mi = 1;
        for(int j=col-1;j>-1;--j){
            //resArr[i][j];
            string cur_str = vec_data[digits[j]-'2'];
            int cur_len = cur_str.length();
            for(int k=0;k<row;k){
                for(int n=0;n<cur_str.length();++n){
                    char c = cur_str[n];
                    for(int x=0;x<mi;++x){
                        //resArr[k][j]= k% vector_data[j].length();
                        res[k][j] = c;
                        if(x<mi)++k;
                    }
                    //++k;
                }
                
            }
            mi = mi * cur_len;
        }
        return res;
    }
};
// @lc code=end


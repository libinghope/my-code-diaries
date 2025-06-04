/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.63%)
 * Likes:    412
 * Dislikes: 0
 * Total Accepted:    32.2K
 * Total Submissions: 90.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */
#include<unordered_map>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    /*滑动窗口法
    双指针法
    1、初始，leftleft指针和rightright指针都指向SS的第一个元素.

    2、将 rightright 指针右移，扩张窗口，直到得到一个可行窗口，亦即包含TT的全部字母的窗口。

    3、得到可行的窗口后，将lefttleftt指 针逐个右移，若得到的窗口依然可行，则更新最小窗口大小。

    4、若窗口不再可行，则跳转至 2。
    */
    string minWindow(string s, string t) {
        unordered_map<string,int> umap;

        for(int i=0;i<s.size();++i){
            string tmp = to_string(s[i]);
            if(umap.count(tmp)==0){
                umap[tmp+"min"] = i;
            }
            umap[tmp+"max"] = i;
        }

        int min_pos = s.size()-1;
        int max_pos = 0;
        for(int j=0;j<t.size();++j){
            string str = to_string(t[j]);
            if(umap.count(str+"max")){
                int index = umap[str+"max"];
                if(index>max_pos){
                    max_pos = index;
                }
                if(index < min_pos){
                    min_pos = index;
                }
            }else{
                return "";
            }
        }
        return s.substr(min_pos,max_pos-min_pos);



    }
};
// @lc code=end


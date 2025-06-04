/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.04%)
 * Likes:    229
 * Dislikes: 0
 * Total Accepted:    35.2K
 * Total Submissions: 76K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    /*分割字符串，注意最大值不能超过255
    最短一位，最长3位
    首位是0，直接拿出来
    插入3个.，然后判断是否是有效的IP地址
    */

    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4) return ret;
        vector<string> path;
        DFS(0,path,s);
        return ret;
    }
    void DFS(int pos,vector<string> &path,string &s){
        /*先判断剩余的位数，是否还能构成ip格式，每段ip最多是3位,剩余位数必须<=3*left*/
        int maxLen = (4-path.size()) * 3;
        if(s.size() - pos > maxLen) return;
        if(path.size()==4 && pos==s.size()){//满足条件
            string ans = "";
            ans = path[0]+"."+path[1]+"."+path[2]+"."+path[3];
            ret.push_back(ans);
            return;
        }
        //回溯的典型模式，循环递归
        for(int i=pos;i-pos+1<4;++i){
            string subip = s.substr(pos,i-pos+1);//截取字符串作为四分之一ip
            if(subip.size()>3) return;
            if(!isValid(subip)) continue;
            path.push_back(subip);
            DFS(i+1,path,s);
            path.pop_back();
        }
    }
    bool isValid(string subip){
        int val = atoi(subip.c_str());
        if(val>255) return false;
        if(subip.size()>=2 && subip[0]=='0') return false;
        return true;
    }

private:
    vector<string> ret;
};
// @lc code=end


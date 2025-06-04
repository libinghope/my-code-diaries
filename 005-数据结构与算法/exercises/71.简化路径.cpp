/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 *
 * https://leetcode-cn.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (38.81%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    33.5K
 * Total Submissions: 86K
 * Testcase Example:  '"/home/"'
 *
 * 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
 * 
 * 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..）
 * 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
 * 
 * 请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 /
 * 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："/home/"
 * 输出："/home"
 * 解释：注意，最后一个目录名后面没有斜杠。
 * 
 * 
 * 示例 2：
 * 
 * 输入："/../"
 * 输出："/"
 * 解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
 * 
 * 
 * 示例 3：
 * 
 * 输入："/home//foo/"
 * 输出："/home/foo"
 * 解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
 * 
 * 
 * 示例 4：
 * 
 * 输入："/a/./b/../../c/"
 * 输出："/c"
 * 
 * 
 * 示例 5：
 * 
 * 输入："/a/../../b/../c//.//"
 * 输出："/c"
 * 
 * 
 * 示例 6：
 * 
 * 输入："/a//b////c/d//././/.."
 * 输出："/a/b/c"
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    需要返回上一层，大概率要使用栈
    从前向后扫描，多斜杠的换成一个斜杠
    遇到.的跳过，遇到..的返回上一级
    最后是斜杠的去掉
    */

       string simplifyPath(string path) {
        vector<string> path_list;
        vector<string> path_list2;
        string res = "/";
        split(path, path_list, "/");
        for(string p : path_list){
            if(p == ".") continue;
            else if(p == "..") {
                if(!path_list2.empty())
                    path_list2.pop_back();
                continue;
            }
            path_list2.push_back(p);
        }
        for(int i = 0; i < path_list2.size(); i++){
            if(i != 0) res += "/" + path_list2[i];
            else res += path_list2[i];
        }
        return res;
    }

   void split(string& s, vector<string>& v, string c)
    {
        int start, end;
        start = 0;
        end = s.find(c);
        while(end != std::string::npos)
        {
            string tmp = s.substr(start, end-start);
            if(tmp != "")
                v.push_back(s.substr(start, end-start));
        
            start = end + c.size();
            end = s.find(c, start);
        }
        if(start != s.length())
            v.push_back(s.substr(start));
    }
};
// @lc code=end


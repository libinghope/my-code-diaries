/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 *
 * https://leetcode-cn.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (45.41%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 18.7K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * 给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。
 * 
 * 下图是字符串 s1 = "great" 的一种可能的表示形式。
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * 在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。
 * 
 * 例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * 我们将 "rgeat” 称作 "great" 的一个扰乱字符串。
 * 
 * 同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * 我们将 "rgtae” 称作 "great" 的一个扰乱字符串。
 * 
 * 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "great", s2 = "rgeat"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "abcde", s2 = "caebd"
 * 输出: false
 * 
 */
#include<string>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
/*
解题思路
我们先来思考两个字符串S和T在什么情况下是扰乱字符串：
首先，这两个字符串长度要想等，
其次，这两个字符串组成要一样
然后，S和T中，至少存在一个i，使得S的前半段和T的前半段扰动，S后半段和T后半段扰动；或者S前半段和T后半段扰动，S后半段和T前半段扰动；
翻译成形式语言即使：
1.length(S)==length(T)
2.sort(s)==sort(T)
3.至少存在一个整数i在[1,length(S)],使得(~符号表示是扰动字符串)：
S(0:i)~T(0:i) && S(i:end)~T(i:end)
or S(0:i)~T(end-i:end) && S(end-i:end)~T(0:i)
 */
    bool isScramble(string s1, string s2) {
        if(map_res.count(s1+s2)) return map_res[s1+s2];
        int len1 = s1.size();
        int len2 = s2.size();
        unordered_map<char,int> umap1,umap2;
        if(len1!=len2) return false;
        if(s1.compare(s2)==0) return true;
        for(int i=0;i<len1;++i){
            umap1[s1[i]] = umap1.count(s1[i]) ? umap1.count(s1[i])+1 : 1;
            umap2[s2[i]] = umap2.count(s2[i]) ? umap2.count(s2[i])+1 : 1;
        }
        unordered_map<char,int>::iterator iter;
        for(iter=umap1.begin();iter!=umap1.end();++iter){
            if(iter->second != umap2[iter->first]) return false;
        }

        for(int j=1;j<len1;++j){
            if(isScramble(s1.substr(0,j),s2.substr(0,j)) && 
            isScramble(s1.substr(j),s2.substr(j))){
                map_res[s1+s2]=true;
                return true;
            }
            if(isScramble(s1.substr(0,j),s2.substr(len1-j)) && 
            isScramble(s1.substr(j),s2.substr(0,len1-j))){
                map_res[s1+s2]=true;
                return true;
            }
        }
        map_res[s1+s2]=false;
        return false;
    }
    private:
    unordered_map<string,bool>map_res;
};
// @lc code=end


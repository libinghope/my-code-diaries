/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 *
 * https://leetcode-cn.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (69.11%)
 * Likes:    82
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 11.3K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n, 返回从 1 到 n 的字典顺序。
 * 
 * 例如，
 * 
 * 给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
 * 
 * 请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。
 * 
 */

// @lc code=start
class Solution {
public:
    //又是一个十叉树的题
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for(int i=1;i<10;++i){
            DFS(n,i,ret);
        }
        return ret;
    }
    void DFS(int n,int cur_root,vector<int>& ret){
        if(cur_root>n) return;
        ret.push_back(cur_root);
        cur_root *= 10;
        for(int i=0;i<10;++i){
            DFS(n,cur_root+i,ret);
        }
    }
};
// @lc code=end


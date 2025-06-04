/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.16%)
 * Likes:    238
 * Dislikes: 0
 * Total Accepted:    43.2K
 * Total Submissions: 58.8K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    第一感觉，DFS+回溯
    回溯算法的模板如下
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
    */
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        backtrack(path,1,n,k);
        return ret;
    }
    void backtrack(vector<int> path,int start, int n, int k){
        if(path.size()>=k) {
            ret.push_back(path);
            return;
        }
        for(int i=start;i<=n;++i){
            path.push_back(i);
            backtrack(path,i+1,n,k);

            path.pop_back();
        }
    }
    private:
    vector<vector<int> > ret;
};
// @lc code=end


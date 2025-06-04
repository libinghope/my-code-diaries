/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (68.59%)
 * Likes:    587
 * Dislikes: 0
 * Total Accepted:    79.4K
 * Total Submissions: 115.6K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*首先排序
    从第一个数开始，a[0]*1与后面的值相加，直到大于target
    然后a[0]*2,与后面的值相加,直到大于target
    a[0] *n>target停止，开始对a[1]进行如上操作

    不排序的方法，DFS+剪枝
    对于数组中的每一个元素，要么选择它，要么不选择它
    如此便可以DFS搜索
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        DFS(candidates,target,0);
        return ret;
    }
    void DFS(vector<int>& candidates,int target,int pos){
        if(target==0){
            ret.push_back(path);
            return;
        }
        if(target<0){//剪枝的情况
            return;
        }
        if(pos >= candidates.size()){
            return;
        }

        //如果选择当前值(可重复选取)
        path.push_back(candidates[pos]);
        DFS(candidates,target - candidates[pos],pos);
        path.pop_back();

        //不选择当前值
        DFS(candidates,target,pos+1);
    }

    private:
    vector<int> path;
    vector<vector<int>> ret;
};
// @lc code=end


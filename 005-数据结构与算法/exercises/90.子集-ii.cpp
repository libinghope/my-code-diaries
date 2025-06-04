/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (59.23%)
 * Likes:    187
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 47.1K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*回溯法
    void backtrack(vector<int>path,vector<int>&nums){
        if(path.size()==t){
            res.add(path);
            return path;
        }
        for(数据 in 集合){
            path.add(数据)
            backtrack()

            path.pop()
        }
    }
    
    */
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> path;
        DFS(nums,path,0);

        return ret;
    }
    //path是否需要是引用，不要紧的，无论是否引用，当ret.push_back()
    void DFS(vector<int>& nums, vector<int> path, int start){
        ret.push_back(path);//因为是求幂集，每次进入函数都是一个新的子集(前序遍历),都要存放进结果集

        for(int i=start;i<nums.size();++i){
            //因为已经排序了，所以只要保证当前元素比前一个大就可以保证是没用过的
            if(i>start && nums[i-1] == nums[i]) continue;
   
            path.push_back(nums[i]);

            DFS(nums,path,i+1);
            path.pop_back();
        }
    }
    private:
    vector<vector<int>> ret;
};
// @lc code=end


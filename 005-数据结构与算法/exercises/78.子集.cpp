/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.78%)
 * Likes:    521
 * Dislikes: 0
 * Total Accepted:    76.4K
 * Total Submissions: 99.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    回溯法模板
    void backtrack(path,nums){
        if(条件满足){
            result.add(path);
        }
        for(选择 in 选择列表){
            做选择
            backtrack(path,nums)

            撤销选择
        }
    }
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<int> path;
        for(int i=0;i<=len;++i){
            backtrack(path,0,nums,i);
        }
        return ret;
    }
    void backtrack(vector<int> path,int start,vector<int>& nums,int l){
        if(path.size()==l){
            ret.push_back(path);
            return;
        }
        for(int j=start;j<nums.size();++j){
            path.push_back(nums[j]);
            backtrack(path,j+1,nums,l);

            path.pop_back();
        }

    }
    private:
    vector<vector<int>> ret;
};
// @lc code=end


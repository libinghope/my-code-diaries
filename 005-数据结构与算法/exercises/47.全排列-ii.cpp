/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (57.37%)
 * Likes:    256
 * Dislikes: 0
 * Total Accepted:    48.7K
 * Total Submissions: 84.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
 public:
     vector<vector<int>> permuteUnique(vector<int>& nums){
        res.clear();
        if(nums.size()==0) return res;
        used = vector<bool>(nums.size(),false);
        sort(nums.begin(),nums.end());
        vector<int> path;
        generatePermutation(nums,path);
        return res;
    }

private:
    void generatePermutation(vector<int>& nums,vector<int>&path){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            generatePermutation(nums,path);

            //回溯
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>>res;
    vector<bool>used; 
};
// @lc code=end


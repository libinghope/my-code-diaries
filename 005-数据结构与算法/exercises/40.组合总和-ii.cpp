/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.66%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    48.9K
 * Total Submissions: 80.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    DFS算法+剪枝
    */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        int left = 0,right = candidates.size()-1;
        int mid = 0;
        if(candidates[0]> target) return ret;
        if(candidates[candidates.size()-1]>=target) mid = candidates.size()-1;
        else{
            //二分法，排除掉比target大的数
            while(left<=right){
                mid = (left+right) / 2;
                if(candidates[mid]>target && candidates[mid-1]<=target){
                    break;
                }else if(candidates[mid]>target && candidates[mid-1]>target){
                    right = mid-1;
                }else if(candidates[mid]<target){
                    left = mid+1;
                }
            }
        }
   
        DFS(candidates,target,0,mid);

        return ret;
    }
    void DFS(vector<int>& candidates,int target,int start,int end){
        if(target==0){
            ret.push_back(path);
            return;
        }
        if(target<0){//剪枝
            return;
        }

        for(int i=start;i<=end;++i){
            //过滤掉重复的情况
            if(i>start && candidates[i-1]==candidates[i]) continue;
            path.push_back(candidates[i]);
            DFS(candidates,target-candidates[i],i+1,end);

            path.pop_back();
        }


    }

    private:
    vector<int> path;
    vector<vector<int>> ret;
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.35%)
 * Likes:    587
 * Dislikes: 0
 * Total Accepted:    98.1K
 * Total Submissions: 131.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    数字不重复，只需要暴力遍历即可
    */

    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        //总共有len的阶乘种组合形式
        int sum = 1;
        for(int i=2;i<=len;++i){
            sum *= i;
        }
        bool *used = new bool[len]{false};
        vector<int> path;
        DFS(nums,path,len,used);
        return ret;
    }

    void DFS(vector<int>& nums,vector<int> path,int len,bool used[]){
        if(path.size()==len){
            ret.push_back(path);
            return;
        }
        for(int i=0;i<len;++i){
            if(!used[i]){
                path.push_back(nums[i]);
                used[i] = true;

                DFS(nums,path,len,used);
                //回溯到此处，说明重复了
                used[i] = false;
                path.pop_back();
            }
        }
    }
    private:
    vector<vector<int> > ret;
};
// @lc code=end


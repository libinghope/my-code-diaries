/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> _map;
        for(int i=0;i<nums.size();i++){
            if(_map.count(target-nums[i])){
                return {_map[target-nums[i]],i};
            }
            _map[nums[i]] = i;
        }
        return {-1,-1};
    }
};
// @lc code=end


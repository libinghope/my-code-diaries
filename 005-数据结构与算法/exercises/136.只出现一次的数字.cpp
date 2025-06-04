/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (65.72%)
 * Likes:    1109
 * Dislikes: 0
 * Total Accepted:    164.5K
 * Total Submissions: 249.7K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */
#include<unordered_map>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    //风骚的异或操作,出现两次的变成零
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int first = nums[0];
        for(int i = 1; i<nums.size();i++) {
            first = first ^ nums[i];
        }
        return first;
    }
    int singleNumber2(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int n : nums){
            if(map.count(n)){
                map[n] = 2;
            }else{
                map[n] = 1;
            }
        }
        unordered_map<int, int>::iterator it=map.begin();
        while (it!=map.end())
        {
            if(it->second == 1){return it->first;}
            it++;
        }
        
        return map[1];
    }
};
// @lc code=end


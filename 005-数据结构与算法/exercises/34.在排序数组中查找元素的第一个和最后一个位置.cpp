/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (39.17%)
 * Likes:    369
 * Dislikes: 0
 * Total Accepted:    77.7K
 * Total Submissions: 197.8K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*log(n)的时间复杂度，不用想一定是二分法了
    二分法，找到目标值，然后左右移动找到重复的目标值，获取第一个和最后一个
    的下标
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int start = -1;
        int end = -1;
        vector<int> ret;
        while(left<=right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                //左右移动，找到开始和末尾
                start = mid;
                end = mid;
                while(0<=start && nums[start] == target){
                    --start;
                }
                start++;
                while(end< nums.size() && nums[end] == target){
                    ++end;
                }
                end--;
                break;
            }
            if(nums[mid] > target){
                right = mid - 1;
            }
            if(nums[mid] < target){
                left = mid+1;
            }
        }
        ret.push_back(start);
        ret.push_back(end);
        return ret;
    }
};
// @lc code=end


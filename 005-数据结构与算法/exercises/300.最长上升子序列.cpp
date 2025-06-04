/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (44.16%)
 * Likes:    633
 * Dislikes: 0
 * Total Accepted:    86.9K
 * Total Submissions: 196.8K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */

// @lc code=start
class Solution {
public:
    /*时间复杂度为n平方的方法好想，关键如何实现nlog(n)的时间复杂度
    维护一个等长的数组vec[]，遍历数组，如果当前元素nums[i]比vec最后一个数
    还大，就在后面追加nums[i],否则二分查找vec中第一个比nums[i]大的数，覆盖之
    直到数组最后
    */
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> vec;
        vec.push_back(nums[0]);
        for(int n: nums){
            if(n>vec[vec.size()-1]) {
                vec.push_back(n);
            }else if(n==vec[vec.size()-1]){
                continue;
            }
            else{
                auto pos = binaryFindPos(vec,n);
                vec[pos] = n;
            }
        }
        return vec.size();
    }
    //二分查找第一个比n大的数
    int binaryFindPos(vector<int>& vec,int n){
        if(vec[0]>=n) return 0;
        int start = 0;
        int end = vec.size()-1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(mid > 0 && vec[mid]>= n && vec[mid-1]<n) return mid;
            if(mid > 0 && vec[mid-1]>n) end = mid -1;
            if(vec[mid] < n) start = mid+1;
        }
        return 0;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.91%)
 * Likes:    435
 * Dislikes: 0
 * Total Accepted:    103.9K
 * Total Submissions: 167.8K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*利用快排思想，枢值 左边有size-k ,右边有k-1个时候 此时的枢值就是答案
    需要注意重复元素的情况
    */
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        return nums[nums.size()-k];
    }
};
// @lc code=end


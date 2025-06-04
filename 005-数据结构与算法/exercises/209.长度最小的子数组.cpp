/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (41.93%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    37.5K
 * Total Submissions: 89.2K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
 * 
 * 示例: 
 * 
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 */

// @lc code=start
class Solution
{
public:
    int min(int a, int b)
    {
        return a > b ? b : a;
    }

    int minSubArrayLen(int s, vector<int>& nums)
    {
        int numsSize = nums.size();
        if (nums.size() == 0)
            return 0;

        // 滑动窗口， l/r分别是滑窗的左右index
        int l = 0, r = 0, sum = 0, minLen = numsSize; /*注意题意求minLen故初始化为numsSize */
        while (r < numsSize)
        {
            sum += nums[r]; /* 基础操作就是滑窗右移，不断r++，求部分前缀和 */
            while (sum >= s && r >= l)
            {                                      /* 更新minLen的条件 */
                minLen = min(minLen, (r - l + 1)); /* 更新minLen */
                sum -= nums[l];                    /* 遍历整串求所有minLen，因此滑窗l++，注意此处可能向右多次while  */
                l++;
            }
            r++;

            if (r - l == numsSize && sum < s)
            { /* 最后2个case挂了，发现可能总sum不够，添加特殊判断 */
                // printf("min = %d---sum = %d", r-l+1, sum);
                minLen = 0;
            }
        }

        return minLen;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (48.42%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    35.7K
 * Total Submissions: 73.5K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    思路：
    largest = 1,cur_largest
    把所有的数据放入hashset，然后逐个检查hashset.count(cur_num-1),直到不连续
    同时记录当前长度cur_largest，如果大于最大长度就更新最大长度
    */
    int longestConsecutive(vector<int>& nums) {

    }
};
// @lc code=end


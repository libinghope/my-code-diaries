/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (48.43%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 58.9K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    方法1，全排列，然后排序

    方法2，假设n=6,k=373

    以1开头的排列有 5!个
    以2开头的排列有 5!个
    ···
    以n开头的排列有 5！个
    以上总共有 5！*6 =6！个
    所以对于n有 n!*(n-1)!个排列
    nums=[1,2,3···，n]
    1、所以 第123个全排列的第一个数为nums[373/5!] = 4
    2、从nums中去掉4,
    对剩下的数nums2=[1,2,3,5,6]进行全排列
    也就是找到nums2全排列的第373-4*5!即373%5!个数
    重复以上过程
    */
    string getPermutation(int n, int k) {
        
    }
};
// @lc code=end


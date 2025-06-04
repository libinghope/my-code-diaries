/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (46.97%)
 * Likes:    447
 * Dislikes: 0
 * Total Accepted:    123.9K
 * Total Submissions: 263.3K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = 0;
        int pos2 = 0;
        vector<int>::iterator begin = nums1.begin();
        while(pos1 < m || pos2<n){
            if(pos1==(m-1) && pos2 < n){
                nums1.insert(nums1.end(),nums2[pos2++]);
            }
            if(nums2[pos2] <= nums1[pos1]){
                nums1.insert(begin+pos1,nums2[pos2]);
                if((pos2++)==n){break;}
            }else{
                pos1++;
            }
        }
    }
};
// @lc code=end


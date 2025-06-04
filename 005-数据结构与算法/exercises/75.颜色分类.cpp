/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (54.68%)
 * Likes:    380
 * Dislikes: 0
 * Total Accepted:    70.8K
 * Total Submissions: 129.4K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    桶排序或者计数排序需要两次扫描
    只做一次扫描,使用常数空间
    */
    void sortColors(vector<int>& nums) {
        int first1_pos = 0;
        int first2_pos = 0;
        for(int i=0;i<nums.size();++i){
            //其实就nums[i],nums[i+1]就6种情况
            if(nums[i]==1){
                swap(nums[i],nums[first2_pos]);
                first2_pos++;
            }else if(nums[i]==0){
                swap(nums[i],nums[first1_pos]);
                first1_pos++;
                swap(nums[i],nums[first2_pos]);
                first2_pos++;
            }
        }
    }
};
// @lc code=end


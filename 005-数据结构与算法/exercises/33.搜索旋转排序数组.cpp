/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.46%)
 * Likes:    582
 * Dislikes: 0
 * Total Accepted:    91K
 * Total Submissions: 249.2K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */
#include<vector>
// @lc code=start
class Solution {
public:
    /*
    要求复杂度必须是 O(log n),基本确定就是二分查找了
    关键数组的元素不是严格升序排列的
    思路，找到旋转的那个点 a[i],a[i]>a[i+1],时间复杂度log(n)
    判断target的位置是a[0]-a[i],a[i+1]-a[len-1]哪个区间
    然后折半查找 时间复杂度还是log(n)
    总复杂度还是log(n)

    一开始的想法是错误的，可以直接二分查找,只需要特殊处理一下就好
    */
    int search(vector<int>& nums, int target) {
        //二分查找
        int start = 0,end = nums.size() - 1;
        while(start<=end){
            int mid = (start + end) >> 1;
            if(target==nums[mid]) return mid;
            if(nums[start] <= nums[mid]){  //左边升序
                if(target >= nums[start] && target <= nums[mid]){//在左边范围内
                    end = mid-1;
                }else{//只能从右边找
                    start = mid+1;
                }

            }else{ //右边升序
                if(target >= nums[mid] && target <= nums[end]){//在右边范围内
                    start = mid +1;
                }else{//只能从左边找
                    end = mid-1;
                }
            }
        }
    return -1;
    }
};
// @lc code=end


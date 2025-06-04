/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (37.07%)
 * Likes:    2338
 * Dislikes: 0
 * Total Accepted:    162.9K
 * Total Submissions: 438.4K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //既然要求时间复杂度为log(m+n),基本可以确定是折半查找了
        /*假设 两个集合 A B,也就是nums1,nums2
         1、 首先将集合A用一个 | 划分为两个部分m_left,m_right，如下图所示
           A[1],A[2],A[3]···A[i]···|···A(m-1),A(m)  共m+1种方式

        2、将集合B 用同样的方式进行划分得到 n_left,n_right
            B[1],B[2]···B[j]···|···B[n]

        3、将m_left和n_left 放入一个集合A，将m_right,n_right放入一个集合B
              left_part                  right_part
          A[1],A[2],A[3]···A[i]       | A[i+1]···A[m]
          B[1],B[2],B[3]···B[j]       | B[j+1]···B[n]

        4、则当 len(left_part) == len(right_part)时候即(i+j == m-i+n-j)，我们就已经划分好了两个集合

          此时 (max(A[i],B[j]) + min(A[i+1],B[J+1])) / 2 就是要求的中位数

          此时必定有 A[i] < B[j+1] && B[j] < A[i+1]

          说白了就是找到i的位置，i的位置确定了，j也就确定了  j = (m+n-2i)/2

          要在 A中找到i的位置，用折半查找的方法
        */
        
        int m = nums1.size();
        int n = nums2.size();
        if(0 == n){return (nums1[(m-1)/2]+nums1[m/2]) / 2.0;}
        if(0 == m){return (nums2[(n-1)/2]+nums2[n/2]) / 2.0;}
        if(m > n) {
            vector<int> tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
            m = nums1.size();
            n = nums2.size();
        };

        //现在已经确保 m < n

        int i = m / 2;//假设A分割之后左边有i个 B分割之后左边有j个
        int start = 0;
        int end = m-1; 
        int j = (m+n-2*i) / 2;
        int max_left,min_right;
        while(i<=m){
            if(0<i && 0<j && j< n && nums1[i-1] > nums2[j]){
                //说明左边放i个放多了，丢掉当前的右边一半,(i的值偏大了，i 应该调小，丢掉右边)
                end = i-2;
                //start = start;
                i = start + (end - start)/2;
                j = (m+n-2*i) / 2;
            }else if(0<j && 0<= i && i <m && nums2[j-1] > nums1[i]){
                //说明i的值偏小了，i 应该调大，丢掉左边
                //end = end;
                start = i;
                if(end-start <2){
                    i = start + 1;
                }else{
                    i = start + (end - start)/2;
                }
                
                j = (m+n-2*i) / 2;
            }else{
                //找到了,结果一定就在i的旁边
                //也就是说A集合的前i个元素在左边
                if(i==0){//A集合全部在右边 j必定不能为0
                     max_left = nums2[j-1];
                }
                else if(i == m){//A集合全部在左边
                    if(j>0){
                        max_left = nums1[i-1] > nums2[j-1] ? nums1[i-1]: nums2[j-1];
                    }
                    else{
                        max_left = nums1[i-1];
                    }
                }else{
                    if(j>0){
                        max_left = nums1[i-1] > nums2[j-1] ? nums1[i-1]: nums2[j-1];
                    }
                    else{
                        max_left = nums1[i-1];
                    }
                }
                if(j==0){
                    if(i==m)
                        min_right = nums2[j];
                    else{
                        min_right = nums2[j] > nums1[i] ? nums1[i] : nums2[j];
                    }
                }else if(j==n){
                    min_right = nums1[i];
                }else{
                    if(i==m){
                        min_right = nums2[j];
                    }else{
                        min_right = nums1[i] > nums2[j] ? nums2[j]: nums1[i];
                    }
                }

                return (m+n)%2 != 0 ? min_right : (max_left + min_right) / 2.0;
            }
        }
        return 0.0;
    }
};
// @lc code=end

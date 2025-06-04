/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (61.94%)
 * Likes:    1231
 * Dislikes: 0
 * Total Accepted:    164.4K
 * Total Submissions: 264.2K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 
 */

// @lc code=start
class Solution {
public:
    //2、动态规划的方法
    /*分析过程
    一般动态规划是跟问题的规模相关的，这里应该就是数组的长度n了
    要使用动态规划的方法，一般要将规模为n的问题转化成n-1加常数规模的问题 
    也就是建立 f(n)与f(n-1)的关系
    假设我们已经知道f(n-1)最终结果为(a[i],a[j])，如何通过f(n-1)和(a[i],a[j])得到f(n)呢?
    在这道题当中，n-1条竖线的最大面积为f(n-1),此时选中的是a[i],a[j]两条竖线
    f(n)相当于再在右边加入一条竖线，那么f(n)可以划分为两种情况，最大面积的的两条竖线中
    有第n条或者没有第n条，没有其他情况了~
    a 不包括第n条的话，最大值就是n-1条竖线时候的最大值，即f(n-1)
    b 如果包括第n条竖线的话，由于(a[i],a[j])是n-1规模时候的最大结果，
    此找到包括n在内的最大的面积与f(n-1)比较，大的那个就是最大值

    又由于当n=2时候，最大值是(a[0],a[1])
    当n=3时候，就是比较(a[0],a[1]),(a[0],a[2]),(a[1],a[2])哪个最大
    当n=4时候,经过上一步已经有了f(3),假设为(a[i],a[j]),就是比较(a[i],a[j]),(a[i],a[3]),(a[j],a[3])哪个最大
    
    当n=n时候    ······    比较(a[i],a[j]),(a[i],a[n-1]),(a[j],a[n-1]),取其中的最大值。
    */
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len<2) return -1;
        int i = 0;//此时i,j是n=2时候的解
        int j = len-1;
        int maxArea = 0;

        while (i< j)
        {
            int h = height[i]<height[j] ? height[i] :height[j];
            int tmp = h * (j-i);
            maxArea = maxArea > tmp ? maxArea : tmp;
            if(height[i]<height[j]){
                ++i;
            }else{
                --j;
            }
        }
        
        return maxArea;
    }

    //1、暴力求解法，作为一道难度中等的面试题，显然O(n*n)的时间复杂度是不行的
    int maxArea1(vector<int>& height) {
        int max_area = 0;
        for(int i=0;i<height.size()-1;++i){
            for(int j=i+1;j<height.size();++j){
                int w = j-i;
                int h = height[i] > height[j] ? height[j]:height[i];
                if(h*w > max_area) max_area = h*w;
            }
        }
        return max_area;
    }
};
// @lc code=end


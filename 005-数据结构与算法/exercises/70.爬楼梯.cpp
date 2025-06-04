/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (48.04%)
 * Likes:    883
 * Dislikes: 0
 * Total Accepted:    154.1K
 * Total Submissions: 320.4K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n){
        if(1==n){return 1;}
        if(2==n){return 2;}
        int num = 0;
        int num1 = 1;
        int num2 = 2;

        for(int i=3; i<=n;i++){
            num = num1+num2;
            num1 = num2;
            num2 = num;
        }
        return num;
    }
    //不知道递归为什么会报错
    int climbStairs1(int n) {
        if(1==n){return 1;}
        if(2==n){return 2;}
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
// @lc code=end


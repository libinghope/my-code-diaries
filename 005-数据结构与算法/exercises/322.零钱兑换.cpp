/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (38.83%)
 * Likes:    541
 * Dislikes: 0
 * Total Accepted:    73.7K
 * Total Submissions: 189.5K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */

// @lc code=start
class Solution {
public:

    //算法2 动态规划
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()<=0 || amount<0) return -1;
        if(amount==0) return 0;

        //int* dp = new int[amount+1]{-1};
        vector<int> memo(amount+1,-1);
        memo[0] = 0;
        queue<int> queue;
        for(int i=0;i<coins.size();++i){
            if(coins[i]>amount)continue;
            memo[coins[i]] = 1;
            queue.push(coins[i]);
        }
        while(!queue.empty()){
            int q = queue.front();
            queue.pop();
            bool flag = false;
            for(int coin : coins){
                if(q+coin > amount){
                    continue;
                }
                if(memo[q]+1 < memo[q+coin] || memo[q+coin]==-1){
                    memo[q+coin] = memo[q] + 1;
                    queue.push(q+coin);
                    if(q+coin == amount) return memo[amount];
                }
            }
            if(memo[amount]!=-1) return memo[amount];
        }
        return memo[amount];
    }

    /*
    典型的多数之和，元素可以重复使用

    方法1，带记忆的递归算法
    
    int coinChange1(vector<int>& coins, int amount) {
        if(coins.size()<=0 || amount<0) return -1;
        if(amount==0) return 0;
        //ret = INT_MAX;
        //sort(coins.begin(),coins.end());
        //vector<int> path;
        memo = new int[amount]{0};
        return findWay(coins,amount,0);
        //return ret==INT_MAX ? -1 : ret;
    }
    int findWay(vector<int>& coins, int amount,int count){
        //amount < 0说明无法兑换
        if(amount<0) return -1;
        //amount=0说明应该终止递归,可以理解为兑换0金额的钱需要0个coin
        if(amount==0){
            return 0;
        }
        if(memo[amount-1] != 0) return memo[amount-1];
        int min = INT_MAX;
        for(int i=0;i<coins.size();++i){
            int res = findWay(coins,amount-coins[i],count+1);
            if(res >=0 && res<min){
                min = res + 1;//前面已经减去coins[i]了，这里要加上
            }
        }
        memo[amount-1] = min == INT_MAX ? -1 : min;
        return memo[amount-1];
    }
    */

private:
    //int ret;
    int* memo;
};
// @lc code=end


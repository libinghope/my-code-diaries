/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 *
 * https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (32.62%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 11.1K
 * Testcase Example:  '13\n2'
 *
 * 给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。
 * 
 * 注意：1 ≤ k ≤ n ≤ 10^9。
 * 
 * 示例 :
 * 
 * 
 * 输入:
 * n: 13   k: 2
 * 
 * 输出:
 * 10
 * 
 * 解释:
 * 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;//初始化为cur = 1，k需要自减1
        while (k > 0) {
            long long step = 0, first = cur, last = cur + 1;
            //统计这棵子树下所有节点数（step）
            while (first <= n) { 
                int tmp = n+1 < last ? n+1 : last;
                step += tmp - first;//不能超过n的值，并不是所有节点都有十个子节点
                first *= 10;
                last *= 10;
            }
            if (step <= k) {//不在子树中
                ++cur;
                k -= step;
            } 
            else {//在子树中，进入子树
                cur *= 10;
                --k; 
            }
        }
        return cur;
    }
    /*
    所谓字典序问题，就是10叉树问题
    1-9为根节点的十叉树，从左向右排开就是字典序
    求第k小的数 K，就是找K在这9棵树的哪个位置
    也就是从1开始，一个一个向下向后数，数到第k个
    */
     int findKthNumber1(int n, int k) {
        int p = 0;//记录上一棵树结束的节点数
        int prefix = 1;//前缀从1开始
        int count = 0;
        while(p<k){//找到为止
            count += getCount(prefix,n);
            if(count>=k){//在当前的树中
                //知道prefix了
                //第k-p个数就是要找的目标
                int cur_count = 1;
                int cur_row_prefix = prefix;
                int cur_p = 0;
                int t = 1;
                while(cur_count<k-p){
                    cur_row_prefix *= 10;
                    t *= 10;
                    cur_p = cur_count;
                    cur_count += t;
                }
                return cur_row_prefix + k - p - cur_p-1;
            }else{
                prefix++;
            }
            p = count;
        }
        return p;
    }
    //prefix是前缀，n是上界
    int getCount(int prefix,int n){
        /*
        前缀树(字典排序树)的特点
        1、下层是上层数量的10倍(满树)，树不满的时候，要区别考虑最后一层
        2、下层起点是上层起点数值的10倍
        3、十叉树在最后一层不满，则n必定就是最后一层的某个数
           不满的这一层的节点数为，n-layer_first+1（layer_first为该层第一个节点）
        4、十叉树每层的相邻节点值差1
        */
        int cur_row_prefix = prefix;//从第一层第一个数开始
        int cur_row_count = 1;
        int count = 0;
        while(cur_row_count + cur_row_prefix -1<n){
            count += cur_row_count;
            cur_row_prefix *= 10;
            cur_row_count *= 10;
        }
        /* 树不满的时候，该如何计算最后一层的节点数？ 
           如果十叉树在最后一层不满，则n必定就是最后一层的某个数
           不满的这一层的节点数为，n-layer_first+1（layer_first为该层第一个节点）
        */
        if(cur_row_count + cur_row_prefix>n && (n-cur_row_prefix+1)>0)
        {
            count += (n-cur_row_prefix+1);
        }
        return count;
    }
};
// @lc code=end


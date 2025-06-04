/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long y = 0;
        int z = x;
        while(x!=0){
            y = y*10 +x%10;
            x/=10;
        }
        return y==z;
    }
};
// @lc code=end


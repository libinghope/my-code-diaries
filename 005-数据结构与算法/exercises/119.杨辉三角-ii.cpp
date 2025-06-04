/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (60.37%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    43.9K
 * Total Submissions: 72.6K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dv;
        if(rowIndex==0){
            dv.push_back(1);
            return dv;
        }
        vector<int> lastv = getRow(rowIndex-1);
        dv.push_back(1);
        for(int i=0;i<lastv.size()-1;i++){
            dv.push_back(lastv[i]+lastv[i+1]);
        }
        dv.push_back(1);
        return dv;
    }
};
// @lc code=end


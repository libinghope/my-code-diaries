/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (65.97%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    66.3K
 * Total Submissions: 100.5K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
typedef vector<int> vector_int;
class Solution {
public:
    vector<vector_int> generate(int numRows) {
        vector<vector_int> dv;
        vector_int cur_v;
        if(numRows==0){return dv;}
        if(numRows==1){
            cur_v.push_back(1);
            dv.push_back(cur_v);
            return dv;
        }
        vector<vector_int> n_1v = generate(numRows-1);
        cur_v.push_back(1);
        vector_int tmpv = n_1v[n_1v.size()-1];
        for(int i=0;i<tmpv.size()-1;i++){
            cur_v.push_back(tmpv[i]+tmpv[i+1]);
        }
        cur_v.push_back(1);
        n_1v.push_back(cur_v);
        return n_1v;

    }
};
// @lc code=end


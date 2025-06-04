/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (68.31%)
 * Likes:    367
 * Dislikes: 0
 * Total Accepted:    33.5K
 * Total Submissions: 48.7K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    /*思路 递归的一行一行的去测试不行就回溯*/
    vector<vector<string>> solveNQueens(int n) {
        string line(n,'.');
        solveNQueens(line,0,n);
        return res;
    }
private:
    void solveNQueens(string& line,int row,int n){
        if(matrix.size()==n){//满足条件
            ret.push_back(matrix);
            return;
        }
        for(int i=0;i<n;++i){
            if(check(row,i,n)){//符合条件
                line[i] = 'Q';
                matrix.push_back(line);
                line[i] = '.';//进行下一行探测的准备，初始化为全[.]

                solveNQueens(line,row+1,n);
                //回溯的标准步骤，退回上一步
                matrix.pop_back();
            }
        }
    }
    bool check(int row, int col,int n){
        //检查每一行是否冲突，以(row,col)为交点的米字型检查
        /*从下往上，依次为 row-1，row -2,直到第一行*/
        for(int i=1;i<=row;++i){
            //判断左上角是否冲突
            if(col-i>=0 && matrix[row-i][col-i]=='Q'){
                return false;
            }
            //判断右上角是否冲突
            if(col+i>n && matrix[row-i][col+i]=='Q'){
                return false;
            }
            //判断当前列是否冲突
            if(matrix[row-i][col]=='Q'){
                return false;
            }
        }
        return true;
    }


private:
    vector<vector<string>> ret;//存结果
    vector<string> matrix;//存棋盘
};
// @lc code=end


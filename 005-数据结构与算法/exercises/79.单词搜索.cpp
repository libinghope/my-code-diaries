/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (40.87%)
 * Likes:    370
 * Dislikes: 0
 * Total Accepted:    49.5K
 * Total Submissions: 120.5K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        unordered_map<string,bool> used(false);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(board[i][j]==word[0]){
                    bool r = DFS(board,word,i,j,0);
                    if(r){
                        return true;
                    };
                }
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, string word,int r,int c,int start){
        if(start==word.size()-1) return true;

        board[r][c] += 26;//打上标记，免得重复使用
        //搜索上下左右
        bool ans = false;
        if(r>0){//可以上移
            if(board[r-1][c]==word[start+1]){
                ans = DFS(board,word,r-1,c,start+1);
            }
        }
        if(ans) return true;

        if(r<board.size()-1){//可以下移
            if(board[r+1][c]==word[start+1]){
                ans = DFS(board,word,r+1,c,start+1);
            }
        }
        if(ans) return true;

        if(c<board[0].size()-1){//可以右移
            if(board[r][c+1]==word[start+1]){
                ans = DFS(board,word,r,c+1,start+1);
            }
        }
        if(ans) return true;

        if(c>0){//可以左移
            if(board[r][c-1]==word[start+1]){
                ans = DFS(board,word,r,c-1,start+1);
            }
        }
        board[r][c] -= 26;
        return ans;
    }
};
    // @lc code=end

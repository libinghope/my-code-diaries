/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 *
 * https://leetcode-cn.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (67.76%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    22.1K
 * Total Submissions: 32.6K
 * Testcase Example:  '2'
 *
 * 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
 * 
 * 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: [0,1,3,2]
 * 解释:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * 对于给定的 n，其格雷编码序列并不唯一。
 * 例如，[0,2,3,1] 也是一个有效的格雷编码序列。
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * 示例 2:
 * 
 * 输入: 0
 * 输出: [0]
 * 解释: 我们定义格雷编码序列必须以 0 开头。
 * 给定编码总位数为 n 的格雷编码序列，其长度为 2^n。当 n = 0 时，长度为 2^0 = 1。
 * 因此，当 n = 0 时，其格雷编码序列为 [0]。
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    当n=3的时候，可以在n=2时候的解前面分别加0和加1等到
    n=4的时候，在n=3的前面加0加1得到
    递归地执行,关键是如何调整顺序，使各位只有一个不同
    */
    vector<int> grayCode(int n) {
        vector<int> ret;
        if(n==0){
            ret.push_back(0);
            return ret;
        }
        if(n==1){
            ret.push_back(0);
            ret.push_back(1);
            return ret;
        }
        vector<int> vec_pre=grayCode(n-1);
        vector<int> res(vec_pre);
        swap(vec_pre);
        for(int k : vec_pre){
            res.push_back(k+pow(2,n-1));
        }
        //交换
        return res;
    }
    void swap(vector<int> &vec){
        //交换第一位和最后一位
        int pre_pos = 0;
        int end_pos = vec.size()-1;
        while(pre_pos<end_pos){
            int tmp = vec[pre_pos];
            vec[pre_pos] = vec[end_pos];
            vec[end_pos] = tmp;
            pre_pos++;
            end_pos--;
        }
    }
};
// @lc code=end


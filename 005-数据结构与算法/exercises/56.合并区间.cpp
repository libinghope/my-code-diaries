/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.56%)
 * Likes:    339
 * Dislikes: 0
 * Total Accepted:    67.6K
 * Total Submissions: 165.3K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    /*
    首先根据first排序
    用map存储每一个区间,key=first,value=[first,second](first,second为区间前后值)
    技巧点：遇到first相同的，取second较大的那个
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return intervals;
        //排序完成，其他就好说了
        sort(intervals.begin(), intervals.end(), less<vector<int>>());
        int pos = 0;//表示当前合并后的尾部
        for(int i=1;i<intervals.size();++i){
            //intervals[i][1] >= intervals[i+1][0];
            if(intervals[pos][1] >= intervals[i][0]){
                //pos保持在原地，i继续递增
                //intervals[pos][0] = intervals[i][0];
                intervals[pos][1]= intervals[pos][1] >= intervals[i][1] ? intervals[pos][1]: intervals[i][1];
            }else{
                //不用合并，pos、i都向前走
                intervals[pos+1][0] = intervals[i][0];
                intervals[pos+1][1] = intervals[i][1];
                ++pos;
            }
        }
        intervals.resize(pos+1);//pos后边的删掉
        return intervals;
    }
};
// @lc code=end


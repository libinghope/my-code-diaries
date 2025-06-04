/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (37.35%)
 * Likes:    419
 * Dislikes: 0
 * Total Accepted:    66.6K
 * Total Submissions: 178.3K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
/*
分析过程,
假设有集合A=a[0],a[1]···a[len-1]
所有的解的结果只有两类，包含a0的和不包括a0的
包括a[0]的，就是求解a[1],a[2]···a[len-1] 的三数之和为target-a[0]
不包括a[0]的就是 集合B=a[1],a[2]···a[len-1] 的四数之和为target的解

此时变成了求集合B的四数之和为target的问题
所有结果只有两类，包括a[1]的和不包括a[1]的
包括a[1]的就是求解 a[2],a[3]···a[len-1]的三数之和为target-a[1]
不包括a[1]的就是求解a[2].a[3]···a[len-1]的四数之和为target的解
···
以此类推 直到集合N=a[len-4],a[len-3],a[len-2],a[len-1]
至此求解完毕

*/
// @lc code=start
typedef vector<int> vector_int;
class Solution {
public:
    vector<vector_int> fourSum(vector<int>& nums, int target) {
        vector<vector_int> ret;
        int len = nums.size();
        if(len<4) return ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-3;++i){
            if(i>0 && nums[i]==nums[i-1]) continue;//去重
            //首先求包括nums[i]的所有的解
            //转变成求解nums[i],nums[i+1]···nums[len-1]的三数之和为target-nums[0]的问题
            for(int j=i+1;j<len-2;++j){
                if(j>i+1 && nums[j]==nums[j-1]) continue;//去重
                int start = j+1;
                int end = len-1;
                while(start<end){
                    //cout<<"nums[i]+nums[j]+nums[start]+nums[end]="<<nums[i]+nums[j]+nums[start]+nums[end]<<endl;
                    if(nums[i]+nums[j]+nums[start]+nums[end] == target){
                        vector_int vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[start]);
                        vec.push_back(nums[end]);
                        ret.push_back(vec);
                        ++start;
                        while(start>j && start<end && nums[start]==nums[start-1]){
                            ++start;
                        }
                        --end;
                        while(end>start && end+1<len && nums[end]==nums[end+1]){
                            --end;
                        }
                    }else if(nums[i]+nums[j]+nums[start]+nums[end] < target){
                        //值偏小虚调大start
                        ++start;
                        while(start>j && start<end && nums[start]==nums[start-1]){
                            ++start;
                        }
                    }else{
                        --end;
                        while(end>start && end+1<len && nums[end]==nums[end+1]){
                            --end;
                        }
                    }
                }
            }
            //求解nums[1],nums[2]···nums[len-1]的四数之和为target的问题
            //重新开始循环即可
        }
        return ret;
    }
};
// @lc code=end


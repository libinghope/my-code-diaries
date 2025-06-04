/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.96%)
 * Likes:    1932
 * Dislikes: 0
 * Total Accepted:    186K
 * Total Submissions: 709.5K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include<vector>
using namespace std;

// @lc code=start
typedef vector<int> vector_int;
class Solution {
public:
    /*分析过程
    要求三数之和，对于集合A中的每个元素n来说，所有要找的结果，只有两种情况，包括n的和不包括n的
    
    包括a[0]的和不包括a[0]的所有情况加在一起就是答案
    不包括a[0]的，就是a[1],a[2]···a[len-1]的所有符合答案的情况
    而a[1],a[2]···a[len-1],又可以分为包括a[1]的和不包括a[1]的
    ···以此类推直到最后
    
    包括a[0]的，令start=a[1],end=a[len-1],向中间收缩求解
    包括a[1]的，因为之前已经计算过包括a[0]的,肯定已经计算过包括a[0]和a[1]的，，所以不能再计算包括a[0]的，
    start 要从a[2]开始
    同样当计算包括a[2]的解的时候，已经计算过包括a[0],a[2]| a[1],a[2]的，start要从a[3]开始
    */
    vector<vector<int> > threeSum(vector<int> &nums){
        vector<vector_int> res;
        int len = nums.size();
        if(len<3) return res;
        sort(nums.begin(),nums.end());

        int start = 0;
        int end = 0;
        for(int i=0;i<len-2;++i){
            if(i>0 && nums[i] == nums[i-1]){//去重
                continue;
            }
            start = i+1;
            end = len - 1;
            while(start<end){
                if(nums[i]+nums[start]+nums[end] == 0){
                    vector<int> vectmp;
                    vectmp.push_back(nums[i]);
                    vectmp.push_back(nums[start]);
                    vectmp.push_back(nums[end]);
                    res.push_back(vectmp);
                    //向中间收缩
                    ++start;
                    while(end>start && start>i && nums[start]==nums[start-1]){
                        ++start;
                    }
                    --end;
                    while(start<end && end < len-1 && nums[end]==nums[end+1]){
                        --end;
                    }
                }else if(nums[i]+nums[start]+nums[end] > 0){
                    //大了，需要调小，start和end不能回退到原来状态(会重复)，所以只能end调小
                    --end;
                    while(start<end && end < len-1 && nums[end]==nums[end+1]){
                        --end;
                    }
                }else{
                    ++start;
                    while(end>start && start>i && nums[start]==nums[start-1]){
                        ++start;
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int> > threeSum1(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int > vtemp;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            if(i ==0 ||(i>0 && nums[i] != nums[i-1])){
                int p1 = i+1, p2 = len-1;
                while(p1 < p2){
                    if(nums[p1] + nums[p2] < -nums[i]){
                        p1++;
                    }else if(nums[p1] + nums[p2] == -nums[i]){
                        if(p1 == i+1){
                            vector<int > vtemp{nums[i], nums[p1], nums[p2]};
                            ret.push_back(vtemp);
                            vtemp.clear();

                        }else if(nums[p1] != nums[p1-1]){
                            vector<int > vtemp{nums[i], nums[p1], nums[p2]};
                            ret.push_back(vtemp);
                            vtemp.clear();

                        }
                        p1++,p2--;
                    }else{
                         p2--;
                    }
                }
            }
        }
        return ret;

    }
};
// @lc code=end


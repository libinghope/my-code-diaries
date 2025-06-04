/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (43.33%)
 * Likes:    387
 * Dislikes: 0
 * Total Accepted:    87K
 * Total Submissions: 199.7K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
class Solution {
public:
     int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        if(len<3){return -1;}
        int res = nums[0] + nums[1] + nums[2];
        //最小值都比target大
        if(target < nums[0] + nums[1] + nums[2]) return res;
        //最大值都比target小
        if(target > nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3]){
            return nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3];
        }

        for(int i = 0; i < len-2; ++i){
            int t = target - nums[i];
            int l = i+1, r = nums.size()-1;
            while(l < r){
                //cout << "res: " << res << endl; 
                if(nums[l] + nums[r] == t){
                    return target;
                }else if(nums[l] + nums[r] > t){
                    if(abs(res - target) > abs(nums[l] + nums[r] + nums[i] - target)){
                        res = nums[l] + nums[r] + nums[i];
                    }
                    --r;
                }else{
                    if(abs(res - target) > abs(nums[l] + nums[r] + nums[i] - target)){
                        res = nums[l] + nums[r] + nums[i];
                    }
                    ++l;
                }
            }
        }
        return res;
     }
};
// @lc code=end


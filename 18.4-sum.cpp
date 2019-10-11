/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.60%)
 * Likes:    1286
 * Dislikes: 256
 * Total Accepted:    267.5K
 * Total Submissions: 845.4K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sub(4);

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int curTarget = target - nums[i] - nums[j];
                int front     = j + 1;
                int back      = nums.size() - 1;

                while (front < back) {
                    int curSum = nums[front] + nums[back];
                    int diff   = curTarget - curSum;

                    if (diff > 0)
                        front++;
                    else if (diff < 0)
                        back--;
                    else {
                        sub = {nums[i], nums[j], nums[front], nums[back]};
                        res.push_back(sub);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.74%)
 * Likes:    1378
 * Dislikes: 100
 * Total Accepted:    387.5K
 * Total Submissions: 847.3K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum  = INT_MAX;
        int closestDiff = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++) {
            int front = i + 1;
            int back  = nums.size() - 1;

            while (front < back) {
                int curSum  = nums[i] + nums[front] + nums[back];
                int absdiff = abs(target - curSum);

                if (absdiff < closestDiff) {
                    closestSum  = curSum;
                    closestDiff = absdiff;
                }

                if (curSum < target)
                    front++;
                else if (curSum > target)
                    back--;
                else
                    return curSum;
            }
        }
        return closestSum;
    }
};
// @lc code=end

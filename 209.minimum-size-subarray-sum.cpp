/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (35.72%)
 * Likes:    1751
 * Dislikes: 95
 * Total Accepted:    229.8K
 * Total Submissions: 625.4K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */

// @lc code=start
class Solution {
   public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int curSum = 0;
        int res    = INT_MAX;

        for (; right < nums.size(); right++) {
            curSum += nums[right];
            while (curSum >= s) {
                res = min(res, right - left + 1);
                curSum -= nums[left];
                left++;
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};
// @lc code=end

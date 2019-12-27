/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.32%)
 * Likes:    2319
 * Dislikes: 110
 * Total Accepted:    392.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>(2, -1);

        vector<int> res(2, -1);
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        if (right == nums.size() || nums[right] != target) return res;

        res[0] = right;
        right  = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        res[1] = right - 1;

        return res;
    }
};
// @lc code=end

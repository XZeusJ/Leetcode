/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.35%)
 * Likes:    2568
 * Dislikes: 206
 * Total Accepted:    523K
 * Total Submissions: 931.8K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int res;
        for (auto num : nums) {
            if (cnt == 0) res = num;
            cnt += (num == res) ? 1 : -1;
        }
        return res;
    }
};
// @lc code=end

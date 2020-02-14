/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (55.45%)
 * Likes:    2869
 * Dislikes: 68
 * Total Accepted:    479.5K
 * Total Submissions: 831.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int i) {
        res.push_back(tmp);

        for (; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            helper(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};

// @lc code=end

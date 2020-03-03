/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (43.90%)
 * Likes:    1311
 * Dislikes: 57
 * Total Accepted:    247K
 * Total Submissions: 547.9K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        helper(res, tmp, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int begin) {
        res.push_back(tmp);

        for (int i = begin; i < nums.size(); i++) {
            if (begin < i && nums[i-1] == nums[i]) continue;
            tmp.push_back(nums[i]);
            helper(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end


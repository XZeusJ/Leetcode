/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (42.45%)
 * Likes:    1474
 * Dislikes: 51
 * Total Accepted:    299.1K
 * Total Submissions: 686.4K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size());

        sort(nums.begin(), nums.end());
        backtrack(used, tmp, res, nums);
        return res;
    }
    void backtrack(vector<bool>& used, vector<int>& tmp, vector<vector<int>>& res, vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;

            tmp.push_back(nums[i]);
            used[i] = true;
            backtrack(used, tmp, res, nums);
            tmp.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

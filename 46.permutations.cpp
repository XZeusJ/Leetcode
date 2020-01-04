/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (57.76%)
 * Likes:    2826
 * Dislikes: 90
 * Total Accepted:    486.5K
 * Total Submissions: 821K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteDFS(nums, 0, res);
        return res;
    }
    void permuteDFS(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start >= nums.size()) {res.push_back(nums);return;}
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permuteDFS(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};
// @lc code=end

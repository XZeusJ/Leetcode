/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 *
 * https://leetcode.com/problems/diagonal-traverse-ii/description/
 *
 * algorithms
 * Medium (39.04%)
 * Likes:    229
 * Dislikes: 29
 * Total Accepted:    11.3K
 * Total Submissions: 27.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a list of lists of integers, nums, return all elements of nums in
 * diagonal order as shown in the below images.
 *
 * Example 1:
 *
 *
 *
 *
 * Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,4,2,7,5,3,8,6,9]
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
 * Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
 * Output: [1,4,2,5,3,8,6,9,7,10,11]
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [[1,2,3,4,5,6]]
 * Output: [1,2,3,4,5,6]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i].length <= 10^5
 * 1 <= nums[i][j] <= 10^9
 * There at most 10^5 elements in nums.
 *
 *
 */

// @lc code=start
class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> ma;

        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = 0; j < nums[i].size(); j++) {
                ma[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        for (auto& n : ma) {
            for (auto& c : n.second) {
                res.push_back(c);
            }
        }
        return res;
    }
};
// @lc code=end

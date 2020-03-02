/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (50.06%)
 * Likes:    1139
 * Dislikes: 59
 * Total Accepted:    253.4K
 * Total Submissions: 489.3K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    void helper(int n, int k, int begin, vector<int>& out, vector<vector<int>>& res) {
        // if (res.size() > k || res.size() + n - s + 1 < k) {
        //     return;
        // }
        if (out.size() == k) {
            res.push_back(out);
            return;
        }

        for (int i = begin; i <= n - (k - out.size()) + 1; i++) {
            out.push_back(i);
            helper(n, k, i + 1, out, res);
            out.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> out;
        vector<vector<int>> res;
        helper(n, k, 1, out, res);
        return res;
    }
};
// @lc code=end

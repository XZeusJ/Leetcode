/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (34.25%)
 * Likes:    1135
 * Dislikes: 282
 * Total Accepted:    161.7K
 * Total Submissions: 461.7K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */

// @lc code=start
class Solution {
   private:
    bool helper(vector<bool>& vis, vector<int>& result, int& no, int target) {
        if (result.size() == vis.size()) {
            // boundry case
            if (++no == target) {
                return true;
            } else {
                return false;
            }
        }

        for (int i = 0; i < vis.size(); i++) {
            // choose unvisited number each turn
            if (vis[i]) continue;
            // choose current numbet
            vis[i] = true;
            result.push_back(i + 1);
            // solve sub-problem by recursion
            bool next = helper(vis, result, no, target);
            if (next) return true;
            // reform context when backtrack former problem
            result.pop_back();
            vis[i] = false;
        }
        return false;
    }

   public:
    string getPermutation(int n, int k) {
        vector<bool> vis(n, false);
        vector<int> result;
        int no = 0;
        helper(vis, result, no, k);

        string ans;
        for (auto n : result) {
            ans += to_string(n);
        }
        return ans;
    }
};
// @lc code=end

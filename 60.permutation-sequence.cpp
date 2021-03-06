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
   public:
    string getPermutation(int n, int k) {
        string res;
        string tmp;
        vector<bool> used(n+1);

        backtrack(used, tmp, n, k, res);
        return res;
    }
    void backtrack(vector<bool>& used, string& tmp, int n, int& k, string& res) {
        if (tmp.size() == n) {
            k--;
            if (k == 0) strcpy(res, tmp);
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;

            tmp.push_back(i);
            used[i] = true;
            backtrack(used, tmp, n, k, res);
            tmp.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

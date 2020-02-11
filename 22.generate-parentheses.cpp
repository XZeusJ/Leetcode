/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (57.35%)
 * Likes:    3722
 * Dislikes: 214
 * Total Accepted:    435.3K
 * Total Submissions: 743.1K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, "", res);
        return res;
    }

    void dfs(int left, int right, string out, vector<string> &res) {
        // 因为每一次尝试, 都是用新的字符串变量, 所以无需回溯
        // 在递归终止的时候, 直接把它添加到结果集里即可, 注意与46, 39题进行区分
        if (left == 0 && right == 0) {
            res.push_back(out);
            return;
        }

        if (left > right) return;  // 剪枝 (当左括号可以使用的个数严格大于右括号可以使用的个数, 才进行剪枝)

        if (left > 0) dfs(left - 1, right, out + "(", res);
        if (right > 0) dfs(left, right - 1, out + ")", res);
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (35.92%)
 * Likes:    961
 * Dislikes: 48
 * Total Accepted:    123.9K
 * Total Submissions: 336.7K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * Example 1:
 * 
 * 
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 * 
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 * 
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (m == 0) return 1;
        if (n == 0) return 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        // dp[i][0] = 1, dp[0][j] = 0;
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        // 状态转移
        // s[i-1] == t[j-1]时，dp[i][j] = dp[i-1][j-1] + dp[i-1][j]  dp[i-1][j-1]表示保留s[i-1]的情况，dp[i-1][j]表示移除s[i-1]的情况
        // s[i-1] != t[j-1]时，dp[i][j] = dp[i-1][j]
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

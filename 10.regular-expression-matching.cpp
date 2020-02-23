/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.76%)
 * Likes:    3331
 * Dislikes: 611
 * Total Accepted:    364.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    bool isMatch(string s, string p) {
        // if (p.empty()) return s.empty();
        // bool first_match = (!s.empty()) && (s[0] == p[0] || p[0] == '.');

        // if (p.size() >= 2 && p[1] == '*') {
        //     return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        // } else {
        //     return first_match && isMatch(s.substr(1), p.substr(1));
        // }

        if (s.empty() || p.empty()) return false;

        // state defination
        // dp[i][j] 表示 s的前i个是否能被p的前j个匹配
        int m = s.size();
        int n = p.size();
        bool dp[m + 1][n + 1];

        // init state
        // s和p都为空, 则匹配
        dp[0][0] = true;
        for (int j = 2; j <= n; j++) {
            // p[j-1] 为字符‘*’可以把j-2和j-1处的字符删去
            // 只有[0, j-3] 都为true才可以
            // 因此dp[j-2]也要为true, 才可以说明前j个为true
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        }

        // state function
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // state function
                // if (s[i - 1] == p[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                // if (p[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (p[j - 1] == '*') {
                    // 前一个字符p[j-1]匹配不上, 比如(ab, abc*)
                    // a* only counts as empty
                    dp[i][j] = dp[i][j - 2] ||
                               dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

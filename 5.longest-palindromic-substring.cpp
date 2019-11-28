/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.01%)
 * Likes:    4820
 * Dislikes: 429
 * Total Accepted:    723.6K
 * Total Submissions: 2.6M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {  // 中心扩散算法
        if (s.size() < 2) return s;
        int n = s.size(), start = 0, len = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            // for case of odd length
            int len1 = searchPalindrome(s, i, i);
            // for case of even length
            int len2 = searchPalindrome(s, i, i + 1);

            len = max(len1, len2);
            if (len > maxLen) {
                start  = i - (len - 1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }

    int searchPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (34.74%)
 * Likes:    1173
 * Dislikes: 99
 * Total Accepted:    73K
 * Total Submissions: 210.2K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appears once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 *
 * Example 1:
 *
 *
 * Input: "bcabc"
 * Output: "abc"
 *
 *
 * Example 2:
 *
 *
 * Input: "cbacdcbc"
 * Output: "acdb"
 *
 *
 * Note: This question is the same as 1081:
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 *
 */

// @lc code=start
class Solution {
   public:
    string removeDuplicateLetters(string s) {
        size_t size = s.size();
        if (size < 2) return s;

        bool used[26] = {false};

        int lastAppearIndex[26];
        for (int i = 0; i < size; i++) lastAppearIndex[s[i] - 'a'] = i;

        stack<char> st;
        for (int i = 0; i < size; i++) {
            if (used[s[i] - 'a']) continue;

            while (!st.empty() && st.top() > s[i] &&
                   lastAppearIndex[st.top() - 'a'] >= i) {
                char top = st.top();
                st.pop();
                used[top - 'a'] = false;
            }

            st.push(s[i]);
            used[s[i] - 'a'] = true;
        }

        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

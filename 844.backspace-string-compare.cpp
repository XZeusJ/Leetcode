/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (46.28%)
 * Likes:    1486
 * Dislikes: 78
 * Total Accepted:    200K
 * Total Submissions: 432.2K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 *
 * Note that after backspacing an empty text, the text will continue empty.
 *
 *
 * Example 1:
 *
 *
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 *
 *
 *
 * Example 2:
 *
 *
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 *
 *
 *
 * Example 3:
 *
 *
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 *
 *
 *
 * Example 4:
 *
 *
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 *
 *
 * Note:
 *
 *
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 *
 *
 * Follow up:
 *
 *
 * Can you solve it in O(N) time and O(1) space?
 *
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        stack<int> s_st, t_st;

        stat(S, s_st);
        stat(T, t_st);

        if (s_st.size() != t_st.size()) return false;

        return s_st == t_st;
    }
    void stat(string s, stack<int>& st) {
        for (auto c : s) {
            if (c != '#')
                st.push(c);
            else if (!st.empty())
                st.pop();
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.45%)
 * Likes:    2577
 * Dislikes: 113
 * Total Accepted:    236.2K
 * Total Submissions: 877K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    int longestValidParentheses(string s) {
        int start = 0, res = 0;
        int len = s.size();

        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                if (st.empty())
                    start = i + 1;
                else {
                    st.pop();
                    if (st.empty())
                        res = max(res, i - start + 1);
                    else
                        res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};
// @lc code=end

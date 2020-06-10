/*
 * @lc app=leetcode id=1417 lang=cpp
 *
 * [1417] Reformat The String
 *
 * https://leetcode.com/problems/reformat-the-string/description/
 *
 * algorithms
 * Easy (55.85%)
 * Likes:    86
 * Dislikes: 33
 * Total Accepted:    14.9K
 * Total Submissions: 27K
 * Testcase Example:  '"a0b1c2"'
 *
 * Given alphanumeric string s. (Alphanumeric string is a string consisting of
 * lowercase English letters and digits).
 *
 * You have to find a permutation of the string where no letter is followed by
 * another letter and no digit is followed by another digit. That is, no two
 * adjacent characters have the same type.
 *
 * Return the reformatted string or return an empty string if it is impossible
 * to reformat the string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "a0b1c2"
 * Output: "0a1b2c"
 * Explanation: No two adjacent characters have the same type in "0a1b2c".
 * "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "leetcode"
 * Output: ""
 * Explanation: "leetcode" has only characters so we cannot separate them by
 * digits.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "1229857369"
 * Output: ""
 * Explanation: "1229857369" has only digits so we cannot separate them by
 * characters.
 *
 *
 * Example 4:
 *
 *
 * Input: s = "covid2019"
 * Output: "c2o0v1i9d"
 *
 *
 * Example 5:
 *
 *
 * Input: s = "ab123"
 * Output: "1a2b3"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of only lowercase English letters and/or digits.
 *
 *
 */

// @lc code=start
class Solution {
   public:
    string reformat(string s) {
        string b = "", a = "";

        for (auto& c : s) {
            if (isalpha(c)) {
                a += c;
            } else {
                b += c;
            }
        }

        if (a.size() < b.size()) {
            swap(a, b);
        }
        if (a.size() - b.size() > 1) return {};

        string ans = "";
        for (int i = 0; i < a.size(); i++) {
            ans += a[i];
            if (i >= b.size()) continue;
            ans += b[i];
        }
        return ans;
    }
};
// @lc code=end

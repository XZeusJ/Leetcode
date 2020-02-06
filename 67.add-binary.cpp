/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (40.76%)
 * Likes:    1208
 * Dislikes: 226
 * Total Accepted:    352.6K
 * Total Submissions: 858.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */

// @lc code=start
class Solution {
   public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            int p   = m >= 0 ? a[m--] - '0' : 0;
            int q   = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res     = to_string(sum % 2) + res;
            carry   = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};
// @lc code=end

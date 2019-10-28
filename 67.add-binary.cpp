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
        int apos      = a.size() - 1;
        int bpos      = b.size() - 1;
        int adigit, bdigit, carry = 0;

        string result = "";
        while (apos >= 0 || bpos >= 0 || carry == 1) {
            adigit = bdigit = 0;

            if (apos >= 0) adigit = a[apos--] == '1';
            if (bpos >= 0) bdigit = b[bpos--] == '1';

            // Another way: the digit is 1 if adigit + bdigit + carry == 1 or == 3, but I noticed that
            // XOR is more concise:
            result = static_cast<char>(adigit ^ bdigit ^ carry + '0') + result;
            carry  = adigit + bdigit + carry >= 2;
        }

        return result;
    }
};
// @lc code=end

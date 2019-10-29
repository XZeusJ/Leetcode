/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (31.70%)
 * Likes:    1258
 * Dislikes: 580
 * Total Accepted:    234.5K
 * Total Submissions: 735.9K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        char res[n1 + n2];
        for (char& c : res) c = '0';

        for (int j = n2 - 1; j >= 0; j--) {
            for (int i = n1 - 1; i >= 0; i--) {
                int product    = (num1[i] - '0') * (num2[j] - '0');
                int tmp        = (res[i + j + 1] - '0') + product;
                res[i + j + 1] = (char)(tmp % 10 + '0');
                res[i + j]     = (char)((res[i + j] - '0' + tmp / 10) + '0');
            }
        }

        std::stringstream ss;
        bool seen = false;
        for (char c : res) {
            if (c == '0' && !seen) continue;
            ss << c;
            seen = true;
        }

        return ss.str().size() == 0 ? "0" : ss.str();
    }
};
// @lc code=end

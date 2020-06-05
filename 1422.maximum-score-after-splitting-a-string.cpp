/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 *
 * https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
 *
 * algorithms
 * Easy (53.97%)
 * Likes:    117
 * Dislikes: 8
 * Total Accepted:    14.9K
 * Total Submissions: 27.5K
 * Testcase Example:  '"011101"'
 *
 * Given a string s of zeros and ones, return the maximum score after splitting
 * the string into two non-empty substrings (i.e. left substring and right
 * substring).
 *
 * The score after splitting a string is the number of zeros in the left
 * substring plus the number of ones in the right substring.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "011101"
 * Output: 5
 * Explanation:
 * All possible ways of splitting s into two non-empty substrings are:
 * left = "0" and right = "11101", score = 1 + 4 = 5
 * left = "01" and right = "1101", score = 1 + 3 = 4
 * left = "011" and right = "101", score = 1 + 2 = 3
 * left = "0111" and right = "01", score = 1 + 1 = 2
 * left = "01110" and right = "1", score = 2 + 1 = 3
 *
 *
 * Example 2:
 *
 *
 * Input: s = "00111"
 * Output: 5
 * Explanation: When left = "00" and right = "111", we get the maximum score =
 * 2 + 3 = 5
 *
 *
 * Example 3:
 *
 *
 * Input: s = "1111"
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= s.length <= 500
 * The string s consists of characters '0' and '1' only.
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int maxScore(string s) {
        int res = 0;
        int cnt0 = 0, cnt1 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') cnt1++;
        }

        for (int i = 0; i < s.size() - 1; i++) {  // 左右区域至少为1, 故此阶段不考虑s末尾为0的情况
            if (s[i] == '0') {
                cnt0++;
            } else if (s[i] == '1') {
                cnt1--;
            }
            res = max(res, cnt0 + cnt1);
        }
        return res;
    }
};
// @lc code=end
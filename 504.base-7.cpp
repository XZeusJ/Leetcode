/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (45.82%)
 * Likes:    214
 * Dislikes: 143
 * Total Accepted:    52.9K
 * Total Submissions: 115.3K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 *
 * Example 1:
 *
 * Input: 100
 * Output: "202"
 *
 *
 *
 * Example 2:
 *
 * Input: -7
 * Output: "-10"
 *
 *
 *
 * Note:
 * The input will be in range of [-1e7, 1e7].
 *
 */

// @lc code=start
class Solution {
   public:
    string convertToBase7(int num) {
        if (num < 0) return "-" + convertToBase7(-1 * num);
        if (num < 7) return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
    }
};
// @lc code=end

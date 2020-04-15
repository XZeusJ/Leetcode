/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (37.64%)
 * Likes:    1408
 * Dislikes: 87
 * Total Accepted:    135.4K
 * Total Submissions: 346.5K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note:  
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 */

// @lc code=start
class Solution {
   public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int l_2 = 0, l_3 = 0, l_5 = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(2 * dp[l_2], min(3 * dp[l_3], 5 * dp[l_5]));
            if (dp[i] == 2 * dp[l_2]) l_2 += 1;
            if (dp[i] == 3 * dp[l_3]) l_3 += 1;
            if (dp[i] == 5 * dp[l_5]) l_5 += 1;
        }
        return dp[n - 1];
    }
};
// @lc code=end

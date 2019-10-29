/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (28.63%)
 * Likes:    1011
 * Dislikes: 2430
 * Total Accepted:    372.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        int signx = x > 0 ? 1 : -1;
        int signn = n > 0 ? 1 : -1;
        bool

            double res = 1;
        while (n > 0) {
            res *= x;
            n--;
        }

        res return n > 0 ? res : (double)1 / res;
    }
};
// @lc code=end

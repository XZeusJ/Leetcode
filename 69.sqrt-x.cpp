/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (32.20%)
 * Likes:    931
 * Dislikes: 1565
 * Total Accepted:    433.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid)
                left = mid + 1;
            else
                right = mid;
        }
        return left - 1;
    }
};
// @lc code=end

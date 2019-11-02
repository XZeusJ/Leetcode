/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.91%)
 * Likes:    1348
 * Dislikes: 460
 * Total Accepted:    280.2K
 * Total Submissions: 931.8K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> compositeNum(n, false);
        int sum   = 1;        // typical case 2
        int upper = sqrt(n);  // avoid overflow

        for (int i = 3; i < n; i += 2) {
            if (!compositeNum[i]) {
                sum++;
                if (i > upper) continue;
                for (int j = i * i; j < n; j += i) {
                    compositeNum[j] = true;
                }
            }
        }
        return sum;
    }
};
// @lc code=end

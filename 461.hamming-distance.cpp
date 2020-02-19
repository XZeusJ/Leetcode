/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (70.68%)
 * Likes:    1518
 * Dislikes: 149
 * Total Accepted:    281.4K
 * Total Submissions: 395.9K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 ≤ x, y < 2^31.
 * 
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y;
        int res = 0;
        while (s != 0) {
            res += (s & 1 == 1? 1: 0);
            s >>= 1;
        }
        return res;
    }
};
// @lc code=end


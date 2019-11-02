/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.42%)
 * Likes:    540
 * Dislikes: 121
 * Total Accepted:    130.6K
 * Total Submissions: 322.3K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        
        int left = 0, right = num;
        if (num >= 46340) right = 46340;

        while (left <= right) {
            int mid = (left+right)/2;
            int curSquare = mid*mid;
            if (curSquare == num) return true;
            if (curSquare > num) {right = mid - 1;}
            if (curSquare < num) {left = mid + 1;}
        }
        return false;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (48.85%)
 * Likes:    730
 * Dislikes: 98
 * Total Accepted:    168.9K
 * Total Submissions: 332.9K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0, r = n - 1, u = 0, d = n - 1;
        vector<vector<int>> res(n, vector<int>(n));
        int num = 1, tar = n * n;
        while (num <= tar) {
            for (int i = 1; i <= r; i++) res[u][i] = num++;  // left to right.
            u++;
            for (int i = u; i <= d; i++) res[i][r] = num++;  // top to bottom.
            r--;
            for (int i = r; i >= 1; i--) res[d][i] = num++;  // right to left.
            d--;
            for (int i = d; i >= u; i--) res[i][l] = num++;  // bottom to top.
            l++;
        }
        return res;
    }
};
// @lc code=end

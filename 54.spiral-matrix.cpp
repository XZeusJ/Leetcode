/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (31.62%)
 * Likes:    1665
 * Dislikes: 481
 * Total Accepted:    303.3K
 * Total Submissions: 935.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size(), idx = 0, i = 0, j = 0;
        vector<int> res;
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        for (int k = 0; k < m*n; k++) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = 0;
            int x = i + dirs[idx][0], y = j + dirs[idx][1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == 0) {
                idx = (idx + 1) % 4;
                x = i + dirs[idx][0];
                y = j + dirs[idx][1];
            }
            i = x;
            j = y;
        }
        return res;
    }
};
// @lc code=end

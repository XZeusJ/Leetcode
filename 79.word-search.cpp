/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (32.54%)
 * Likes:    2420
 * Dislikes: 130
 * Total Accepted:    353.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */

// @lc code=start
class Solution {
   private:
    int m;
    int n;
    // bool* visited;

   public:
    bool dfs(int x, int j, string word, bool visited, )

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        bool visited[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = true;
                if (dfs(i, j, word, visited, board)) return true;
                visited[i][j] = false;
            }
        }
        return false;
    }
};
// @lc code=end

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
   public:
    bool backtrack(int x, int y, int curLen, string word, vector<vector<char>>& board) {
        if (board[x][y] != word[curLen]) return false;

        if (word.size() - 1 == curLen) return true;

        char tmp    = board[x][y];
        board[x][y] = '-';
        curLen++;
        if ((0 < x && backtrack(x - 1, y, curLen, word, board))
        ||  (0 < y && backtrack(x, y - 1, curLen, word, board))
        ||  (x < board.size() - 1 && backtrack(x + 1, y, curLen, word, board))
        ||  (y < board[0].size() -1 && backtrack(x, y + 1, curLen, word, board))) {
            return true;
        }
        board[x][y] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(i, j, 0, word, board)) return true;
            }
        }
        return false;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (67.15%)
 * Likes:    701
 * Dislikes: 89
 * Total Accepted:    61K
 * Total Submissions: 90.8K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given an array A of strings made only from lowercase letters, return a list
 * of all characters that show up in all strings within the list (including
 * duplicates).  For example, if a character occurs 3 times in all strings but
 * not 4 times, you need to include that character three times in the final
 * answer.
 *
 * You may return the answer in any order.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: ["cool","lock","cook"]
 * Output: ["c","o"]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] is a lowercase letter
 *
 *
 *
 */

// @lc code=start
class Solution {
   public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int num[100][26] = {0};
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                num[i][(A[i][j] - 'a')]++;
            }
        }

        for (int j = 0; j < 26; j++) {
            for (int i = 1; i < A.size(); i++) {
                num[0][j] = min(num[0][j], num[i][j]);
            }
        }

        for (int i = 0; i < 26; i++) {
            while (num[0][i]--) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};
// @lc code=end

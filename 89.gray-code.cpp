/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (46.87%)
 * Likes:    527
 * Dislikes: 1402
 * Total Accepted:    151.7K
 * Total Submissions: 317.6K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,3,2]
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * For a given n, a gray code sequence may not be uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence.
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: [0]
 * Explanation: We define the gray code sequence to begin with 0.
 * A gray code sequence of n has size = 2^n, which for n = 0 the size is 2^0 =
 * 1.
 * Therefore, for n = 0 the gray code sequence is [0].
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> result(1);
        result[0] = 0;
        for (int i = 1; i <= n; i++) {
            int e = 1 << (i - 1);
            for (int j = result.size() - 1; j >= 0; j--) {
                result.push_back(e + result[j]);
            }
        }
        return result;
    }
};
// @lc code=end

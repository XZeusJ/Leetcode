/*
 * @lc app=leetcode id=1434 lang=cpp
 *
 * [1434] Number of Ways to Wear Different Hats to Each Other
 *
 * https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/
 *
 * algorithms
 * Hard (35.15%)
 * Likes:    214
 * Dislikes: 1
 * Total Accepted:    3.5K
 * Total Submissions: 9.6K
 * Testcase Example:  '[[3,4],[4,5],[5]]'
 *
 * There are n people and 40 types of hats labeled from 1 to 40.
 *
 * Given a list of list of integers hats, where hats[i] is a list of all hats
 * preferred by the i-th person.
 *
 * Return the number of ways that the n people wear different hats to each
 * other.
 *
 * Since the answer may be too large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: hats = [[3,4],[4,5],[5]]
 * Output: 1
 * Explanation: There is only one way to choose hats given the conditions.
 * First person choose hat 3, Second person choose hat 4 and last one hat 5.
 *
 * Example 2:
 *
 *
 * Input: hats = [[3,5,1],[3,5]]
 * Output: 4
 * Explanation: There are 4 ways to choose hats
 * (3,5), (5,3), (1,3) and (1,5)
 *
 *
 * Example 3:
 *
 *
 * Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
 * Output: 24
 * Explanation: Each person can choose hats labeled from 1 to 4.
 * Number of Permutations of (1,2,3,4) = 24.
 *
 *
 * Example 4:
 *
 *
 * Input: hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
 * Output: 111
 *
 *
 *
 * Constraints:
 *
 *
 * n == hats.length
 * 1 <= n <= 10
 * 1 <= hats[i].length <= 40
 * 1 <= hats[i][j] <= 40
 * hats[i] contains a list of unique integers.
 *
 */

// @lc code=start
class Solution {
   public:
    int f[41][1024];
    int mod = 1e9 + 7;

    int numberWays(vector<vector<int>>& hats) {
        // 用n bits来表示n个人是否佩戴了帽子 e.g. 10011011
        // 动态规划 f[i][j]代表前i顶帽子分配完, 状态为j的方案数
        // f[i+1][j] += f[i][j]
        // 枚举k, 考虑第i顶帽子分配给第k个人
        // f[i+1][j | (1 << k)] += f[i][j]

        // 最终结果是求 mask = (1<<n) - 1 时候的数量

        int n = hats.size(), m = 40;
        vector<vector<int>> v(41, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < hats[i].size(); j++) {
                v[hats[i][j]].push_back(i);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                f[i][j] = 0;
            }
        }
        f[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                if (f[i][j] == 0) { // 剪枝
                    continue;
                }
                (f[i + 1][j] += f[i][j]) %= mod;
                for (int k : v[i + 1]) {
                    if ((j & (1 << k)) == 0) {
                        (f[i + 1][j | (1 << k)] += f[i][j]) %= mod;
                    }
                }
            }
        }
        return f[m][(1 << n) - 1];
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (34.97%)
 * Likes:    1690
 * Dislikes: 67
 * Total Accepted:    190.6K
 * Total Submissions: 527K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int max_k = 2;
        int len   = prices.size();
        if (len < 2) return 0;
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(max_k + 1, vector<int>(2)));

        for (int i = 0; i < len; i++) {
            for (int k = max_k; k >= 1; k--) {
                if (i - 1 == -1) {
                    dp[i][k][0] = 0;
                    // 解释：
                    //   dp[i][0]
                    // = max(dp[-1][0], dp[-1][1] + prices[i])
                    // = max(0, -infinity + prices[i]) = 0
                    dp[i][k][1] = -prices[0];
                    //解释：
                    //   dp[i][1]
                    // = max(dp[-1][1], dp[-1][0] - prices[i])
                    // = max(-infinity, 0 - prices[i])
                    // = -prices[i]
                    continue;
                }
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        return dp[len - 1][max_k][0];
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (45.00%)
 * Likes:    5194
 * Dislikes: 97
 * Total Accepted:    400.9K
 * Total Submissions: 869.3K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */

// @lc code=start
class Solution {
   public:
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = mx;
            mx    = max(mx, height[i]);
        }
        mx = 0;

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = min(dp[i], mx);
            mx    = max(mx, height[i]);
            if (dp[i] > height[i]) res += dp[i] - height[i];
        }
        return res;
    }
};
// @lc code=end

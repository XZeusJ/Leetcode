/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.13%)
 * Likes:    3144
 * Dislikes: 134
 * Total Accepted:    283.6K
 * Total Submissions: 921.8K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, imax = 1, imin = 1;
        for (int i = 0; i<nums.size(); i++) {
            // 当负数出现时则imax与imin进行交换再进行下一步计算
            if (nums[i] < 0) {
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            // 令imax为当前最大值，则当前最大值为 imax = max(imax * nums[i], nums[i])
            imax = max(imax*nums[i], nums[i]);
            // 由于存在负数，那么会导致最大的变最小的，最小的变最大的。
            // 因此还需要维护当前最小值imin，imin = min(imin * nums[i], nums[i])
            imin = min(imin*nums[i], nums[i]);

            res = max(res, imax);
        }
        return res;
    }
};
// @lc code=end


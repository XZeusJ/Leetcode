/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.74%)
 * Likes:    4174
 * Dislikes: 133
 * Total Accepted:    285.1K
 * Total Submissions: 651.6K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 *
 *
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        // 由于只关心次数, 故可以用hashtable来来加速运算
        // 由于保存了之前相同前缀和的个数，计算区间总数的时候不是一个一个地加，时间复杂度降到了 O(N)

        // key: 前缀和, value: 关键字对应的前缀和的个数
        unordered_map<int, int> hash;
        hash[0] = 1;
        int ans = 0, sum = 0;
        for (auto num: nums) {
            sum += num;
            ans += hash[sum-k];
            hash[sum]++;
        }
        return ans;
    }
};
// @lc code=end

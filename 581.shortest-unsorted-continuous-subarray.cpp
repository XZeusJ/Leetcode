/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (30.52%)
 * Likes:    2313
 * Dislikes: 120
 * Total Accepted:    108.7K
 * Total Submissions: 353.2K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 *
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 *
 *
 *
 * Note:
 *
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means .
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> cp_nums = nums;
        sort(nums.begin(), nums.end());

        int size = nums.size();
        int l = 0, r = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != cp_nums[i]) {
                l = i;
                break;
            }
        }
        for (int j = size - 1; j >= 0; j--) {
            if (nums[j] != cp_nums[j]) {
                r = j;
                break;
            }
        }

        if (r == 0) return 0;
        return r - l + 1;
    }
};
// @lc code=end

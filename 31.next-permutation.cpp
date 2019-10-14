/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.14%)
 * Likes:    2247
 * Dislikes: 727
 * Total Accepted:    278.8K
 * Total Submissions: 894.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
// https://www.youtube.com/watch?v=quAS1iydq7U
#include <vector>
using namespace std;
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;

        // nd the largest index k such that a[k] < a[k + 1].
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        //If no such index exists, the permutation is the last permutation.
        if (k < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            // Find the largest index l greater than k such that a[k] < a[l].
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            // The values of a[2] and a[3] are swapped to form the new sequence [1,2,4,3].
            swap(nums[k], nums[l]);
            // The sequence after k-index a[2] to the final element is reversed. 
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
// @lc code=end

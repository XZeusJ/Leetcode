/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.88%)
 * Likes:    4644
 * Dislikes: 540
 * Total Accepted:    663.8K
 * Total Submissions: 2.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort method
        // two pointer
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front  = i + 1;
            int back   = nums.size() - 1;

            while (front < back) {
                int sum = nums[front] + nums[back];

                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> triplet(3, 0);
                    triplet = {nums[i], nums[front], nums[back]};
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    while (front < back && nums[front] == triplet[1]) front++;
                    // Processing duplicates of Number 3
                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }

            // Processing duplicates of Number 1
            while (i < nums.size() - 1 && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};
// @lc code=end

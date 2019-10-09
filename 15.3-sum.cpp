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
#include <set>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<int> marked;
        for (int i = 0; i < nums.size(); i++) {
            if (marked.find(i) != marked.end()) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (marked.find(j) != marked.end()) continue;
                for (int k = j + 1; k < nums.size(); k++) {
                    if (marked.find(k) != marked.end()) continue;
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                        marked.insert(nums[i]);
                        marked.insert(nums[j]);
                        marked.insert(nums[k]);
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

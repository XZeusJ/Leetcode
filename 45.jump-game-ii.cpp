/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (28.91%)
 * Likes:    1617
 * Dislikes: 88
 * Total Accepted:    206.3K
 * Total Submissions: 706.1K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */

// @lc code=start
class Solution {
   public:
    int jump(vector<int>& nums) { // bfs methond
        if (nums.size() < 2) return 0;
        int level      = 0;
        int curMaxArea = 0;
        int maxNext    = 0;
        int i          = 0;
        while (curMaxArea - i + 1 > 0) {
            level++;
            for (; i <= curMaxArea; i++) {
                maxNext = max(maxNext, nums[i] + i);
                if (maxNext >= nums.size() - 1) {
                    return level;
                }
            }
            curMaxArea = maxNext;
        }
        return 0;
    }
};
// @lc code=end

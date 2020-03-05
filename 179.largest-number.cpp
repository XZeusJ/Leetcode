/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (26.65%)
 * Likes:    1269
 * Dislikes: 164
 * Total Accepted:    146.6K
 * Total Submissions: 547.5K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */

// @lc code=start
class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return string("0");
        }
        vector<string> strNums(nums.size());
        std::transform(nums.begin(), nums.end(), strNums.begin(), [](int x) {
            return std::to_string(x);
        });

        std::sort(strNums.begin(), strNums.end(), [](const string& x, const string& y) {
            /* x为后面元素，y为前面元素，return true则将x移动到前面 */
            return x + y > y + x;
        });

        return std::accumulate(strNums.begin(), strNums.end(), string());
    }
};
// @lc code=end

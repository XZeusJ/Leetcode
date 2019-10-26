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
    string largestNumber(vector<int> &nums) {
        vector<string> arr;
        for (auto i : nums)
            arr.push_back(to_string(i));
        sort(arr.begin(), arr.end(), [](string &s1, string &s2) { return s1 + s2 > s2 + s1; });
        
        if (arr[0] == "0") return "0";

        string res;
        for (auto s : arr)
            res += s;
        return res;
    }
};
// @lc code=end

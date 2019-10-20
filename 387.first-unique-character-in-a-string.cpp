/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.73%)
 * Likes:    1235
 * Dislikes: 87
 * Total Accepted:    332.7K
 * Total Submissions: 654.8K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */

// @lc code=start
class Solution {
   public:
    int firstUniqChar(string s) {
        if (s.size() == 1) return 0;
        unordered_set<char> c_set;

        int res = __INT_MAX__;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (c_set.find(s[i]) == c_set.end()) {
                c_set.insert(s[i]);
                res = i;
            }
        }
        if (c_set.size() == s.size())
            return -1;
        else
            return res;
    }
};
// @lc code=end

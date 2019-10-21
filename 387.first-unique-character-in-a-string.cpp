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
#include <bitset>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
class Solution {
   public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
        for (char &c : s) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) return i;
        }
        return -1;
        
    }
};
// @lc code=end

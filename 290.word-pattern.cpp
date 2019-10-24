/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (35.67%)
 * Likes:    786
 * Dislikes: 105
 * Total Accepted:    159K
 * Total Submissions: 444.6K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */

// @lc code=start
using namespace std;
class Solution {
   public:
    bool wordPattern(string pattern, string str) {
        std::unordered_map<char, string> c2s;
        std::unordered_map<string, char> s2c;

        int j = 0;
        string word;
        for (int i = 0; i < pattern.size(); i++) {
            if (j >= str.size()) return false;
            word = "";
            while (j < str.size()) {
                if (str[j] != ' ')
                    word += str[j++];
                else {
                    j++;
                    break;
                }
            }

            // if find in map, check if correct
            // else put in map
            if (c2s.find(pattern[i]) != c2s.end()) {
                if (c2s[pattern[i]] != word) return false;
            } else if (s2c.find(word) != s2c.end()) {
                if (s2c[word] != pattern[i]) return false;
            } else {
                c2s[pattern[i]] = word;
                s2c[word]       = pattern[i];
            }
        }
        if (j < str.size()) return false;
        return true;
    }
};
// @lc code=end

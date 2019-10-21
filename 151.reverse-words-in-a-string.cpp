/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (18.02%)
 * Likes:    686
 * Dislikes: 2464
 * Total Accepted:    321K
 * Total Submissions: 1.8M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

// @lc code=start
#include <string>
#include <vector>
#include <sstream> 
#include <iterator> 
#include <iostream> 
using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        // trim s
        s.erase(0, s.find_first_not_of(' '));  //prefixing spaces
        s.erase(s.find_last_not_of(' ') + 1);  //surfixing spaces

        vector<string> strs;
        // s to word vector with reversed sequence
        string word = "";
        auto it     = strs.begin();

        for (auto x : s) {
            if (x == ' ') {
                strs.insert(it, word);
                word = "";
            } else {
                word = word + x;
            }
        }
        strs.insert(it, word);

        // word vector to string
        ostringstream vts;

        if (!strs.empty()) {
            copy(strs.begin(), strs.end(), ostream_iterator<string>(vts, " "));
        }
        return vts.str();
    }
};
// @lc code=end

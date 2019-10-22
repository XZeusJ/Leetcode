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
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        // trim s
        s.erase(0, s.find_first_not_of(' '));  //prefixing spaces
        s.erase(s.find_last_not_of(' ') + 1);  //surfixing spaces

        // s to word vector
        std::regex ws_re("\\s+");  // whitespace
        std::vector<std::string> strs(std::sregex_token_iterator(s.begin(), s.end(), ws_re, -1), std::sregex_token_iterator());

        // reverse
        int i = 0, j = strs.size() - 1;
        while (i < j) {
            swap(strs[i++], strs[j--]);
        }

        // word vector to string
        ostringstream vts;

        if (!strs.empty()) {
            copy(strs.begin(), strs.end() - 1, ostream_iterator<string>(vts, " "));
            // Now add the last element with no delimiter
            vts << strs.back();
        }
        return vts.str();
    }
};
// @lc code=end

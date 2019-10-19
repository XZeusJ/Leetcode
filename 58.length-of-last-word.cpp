/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.31%)
 * Likes:    456
 * Dislikes: 1874
 * Total Accepted:    303.9K
 * Total Submissions: 940.4K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        if (len == 0) return 0;

        int res = 0;

        int i = len - 1;
        while (s[i] == ' ') {
            i--;
        }

        while (i>= 0 && s[i] != ' ') {
            res++;
            i--;
        }

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (64.19%)
 * Likes:    908
 * Dislikes: 581
 * Total Accepted:    517.8K
 * Total Submissions: 804.9K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii
 * characters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for (int i=0; i< len/2; i++) {
            char swap = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = swap;
        }
        // int i = 0, j = s.size() - 1;
        // while(i < j){
        //     swap(s[i++], s[j--]); 
        // }
    }
};
// @lc code=end


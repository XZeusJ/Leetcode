/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (33.01%)
 * Likes:    1073
 * Dislikes: 1519
 * Total Accepted:    507.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int strStr(string haystack, string needle) {
        int i, M = haystack.size();
        int j, N = needle.size();

        if (N == 0) return 0;

        for (i = 0, j = 0; i < M && j < N; i++) {
            if (haystack[i] == needle[j])
                j++;
            else {
                i -= j;
                j = 0;
            }
        }
        if (j == N)
            return i - N;
        else
            return -1;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (38.33%)
 * Likes:    931
 * Dislikes: 271
 * Total Accepted:    236.9K
 * Total Submissions: 616.3K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */

// @lc code=start
using namespace std;
class Solution {
   public:
    bool isIsomorphic(std::string s, std::string t) {
        int m1[256] = {0}, m2[256] = {0}, len = s.size();
        showA(m1, 256);
        for (int i= 0; i<len; i++) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = m2[t[i]] = i+1;
        }

        return true;
    }

    void showA(int a[], int size) {
        for (int i = 0; i < size-1; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
};
// @lc code=end

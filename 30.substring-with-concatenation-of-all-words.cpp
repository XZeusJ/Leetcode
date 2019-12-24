/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (24.21%)
 * Likes:    682
 * Dislikes: 1071
 * Total Accepted:    155.7K
 * Total Submissions: 635.6K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return vector<int>();

        vector<int> res;
        int n   = words.size();
        int len = words[0].size();
        if (s.size() < n * len) return {};  // in case of ** s="a", words=["a","a"] **
        unordered_map<string, int> wordCnt;

        for (auto& word : words) ++wordCnt[word];
        for (int i = 0; i <= s.size() - n * len; i++) {
            unordered_map<string, int> strCnt;
            int j = 0;
            for (j = 0; j < n; j++) {
                string t = s.substr(i + j * len, len);
                if (!wordCnt.count(t)) break;
                ++strCnt[t];
                if (strCnt[t] > wordCnt[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

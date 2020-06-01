/*
 * @lc app=leetcode id=1432 lang=cpp
 *
 * [1432] Max Difference You Can Get From Changing an Integer
 *
 * https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/
 *
 * algorithms
 * Medium (42.57%)
 * Likes:    51
 * Dislikes: 69
 * Total Accepted:    6.9K
 * Total Submissions: 16.2K
 * Testcase Example:  '555'
 *
 * You are given an integer num. You will apply the following steps exactly two
 * times:
 *
 *
 * Pick a digit x (0 <= x <= 9).
 * Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
 * Replace all the occurrences of x in the decimal representation of num by
 * y.
 * The new integer cannot have any leading zeros, also the new integer cannot
 * be 0.
 *
 *
 * Let a and b be the results of applying the operations to num the first and
 * second times, respectively.
 *
 * Return the max difference between a and b.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 555
 * Output: 888
 * Explanation: The first time pick x = 5 and y = 9 and store the new integer
 * in a.
 * The second time pick x = 5 and y = 1 and store the new integer in b.
 * We have now a = 999 and b = 111 and max difference = 888
 *
 *
 * Example 2:
 *
 *
 * Input: num = 9
 * Output: 8
 * Explanation: The first time pick x = 9 and y = 9 and store the new integer
 * in a.
 * The second time pick x = 9 and y = 1 and store the new integer in b.
 * We have now a = 9 and b = 1 and max difference = 8
 *
 *
 * Example 3:
 *
 *
 * Input: num = 123456
 * Output: 820000
 *
 *
 * Example 4:
 *
 *
 * Input: num = 10000
 * Output: 80000
 *
 *
 * Example 5:
 *
 *
 * Input: num = 9288
 * Output: 8700
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 10^8
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int maxDiff(int num) {
        string s_num = to_string(num);
        int min_val = num, max_val = num;

        // 找第一个不是9的数全部替换为9
        size_t flag;
        flag = s_num.find_first_not_of('9');
        if (flag != string::npos) {
            max_val =
                stoi(regex_replace(s_num, regex{s_num.substr(flag, 1)}, "9"));
        }

        if (s_num.front() == '1') {
            for (int i = 1; i < s_num.length(); ++i) {
                if (s_num[i] != '0' && s_num[i] != '1') {
                    min_val = stoi(
                        regex_replace(s_num, regex{s_num.substr(i, 1)}, "0"));
                    break;
                }
            }
        } else {
            min_val =
                stoi(regex_replace(s_num, regex{s_num.substr(0, 1)}, "1"));
        }
        return max_val - min_val;
    }
};
// @lc code=end

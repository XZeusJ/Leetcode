/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (58.33%)
 * Likes:    1246
 * Dislikes: 95
 * Total Accepted:    129.9K
 * Total Submissions: 216.4K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 *
 * Example:
 *
 *
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 *
 * Note:
 *
 *
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 *
 */

// @lc code=start
class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> numbers;
        for (int number : nums) {
            //在 C++ 中，通过 unordered_set 的 insert 方法添加元素时
            //将返回一个 pair<iterator, bool> 对象
            //其 second 为一布尔类型的值，标识是否添加成功
            //注意逻辑非(!)操作符
            if (!numbers.insert(number).second) numbers.erase(number);
            ;  //重复便移除
        }
        //还要转换一下
        vector<int> result(numbers.begin(), numbers.end());
        return result;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        vector<int> result;
        
        for (int i = 0;i<nums.size();i++) {
            auto numberToFind = target - nums[i];
            
            if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }
            
            hash[nums[i]] = i;
        }
        return result;
    }
};
// @lc code=end

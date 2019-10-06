## Two Sums
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

**Example**:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

### Approach 1: Brute Force
Loop through each element x and find if there is another value that equals to target - x

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] == target - nums[i]) {
                        return vector<int>{i,j};
                    }
                }
            }
            throw std::invalid_argument("No two sum solution");
        }
    }

**Complexity Analysis**
* Time complexity:O(n^2). For each element, we try to find its complement by looping through the rest of array which takes O(n) time. Therefore, the time complexity is O(n^2).
* Space complexity:O(1).

### Approach 2: Use Hash Map
While we iterate and inserting elements into the table, we also look back to check if current element's complement already exists in the table. If it exists, we have found a solution and return immediately.

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

**Complexity Analysis**
* Time: O(x). We traverse the list containing n elements only once. Each look up in the table costs only O(1) time.
* Space: O(n). The extra space required depends on the number of items stored in the hash table, which stores at most n elements.


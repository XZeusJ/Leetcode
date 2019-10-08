/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        int start = 0;
        int end = len1;
        int partitionX = (int) ((start + end) / 2);
        int partitionY = (int) ((len1 + len2 + 1) / 2 - partitionX); // invariable point partitionX + partitionY = (x+y+1)/2
        
        while ((nums1[partitionX-1] <= nums2[partitionY] && nums2[partitionY-1] <= nums1[partitionX]) != True) {
            if (nums1[partitionX-1] > nums2[partitionY])
                // move towards left in X
            else
                // move towards right in X
        }
            
        
            
        
    }
};
// @lc code=end


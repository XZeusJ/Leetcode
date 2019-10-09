/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // if nums1 length is greater than switch them so that nums1 is smaller than nums2
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();

        int low  = 0;
        int high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;  // invariable point partitionX + partitionY = (x+y+1)/2

            // edge case: if partitionX is 0, it means nothing is there on left side. Use -INF for maxLeftX
            // same for right side
            int maxLeftX  = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == 0) ? INT_MAX : nums1[partitionX];

            int maxLeftY  = (partitionY == 0) ? INT_MIN : nums1[partitionY - 1];
            int minRightY = (partitionY == 0) ? INT_MAX : nums1[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // we have partitioned array at correct place
                // now compute median
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
    }
};
// @lc code=end

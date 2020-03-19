/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (31.13%)
 * Likes:    2681
 * Dislikes: 221
 * Total Accepted:    281.9K
 * Total Submissions: 869.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int maxPathSum(TreeNode* root, int& val) {
        if (root == nullptr) return 0;
        int left  = maxPathSum(root->left, val);
        int right = maxPathSum(root->right, val);
        int lmr   = root->val + max(0, left) + max(0, right);
        int ret   = root->val + max(0, max(left, right));
        val       = max(val, max(lmr, ret));
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSum(root, val);
        return val;
    }
};
// @lc code=end

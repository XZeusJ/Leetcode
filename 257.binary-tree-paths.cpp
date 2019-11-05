/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (47.49%)
 * Likes:    1108
 * Dislikes: 79
 * Total Accepted:    257K
 * Total Submissions: 537.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return vector<string>();

        vector<string> paths;
        binaryTreePaths(paths, root, to_string(root->val));
        return paths;
    }

    void binaryTreePaths(vector<string>& paths, TreeNode* root, string t) {
        if (!root->left && !root->right) {
            paths.push_back(t);
            return;
        }
        if (root->left) binaryTreePaths(paths, root->left, t + "->" + to_string(root->left->val));
        if (root->right) binaryTreePaths(paths, root->right, t + "->" + to_string(root->right->val));
    }
};
// @lc code=end

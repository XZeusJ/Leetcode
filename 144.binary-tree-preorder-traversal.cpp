/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (52.76%)
 * Likes:    995
 * Dislikes: 46
 * Total Accepted:    392.5K
 * Total Submissions: 740.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return vector<int>();

        vector<int> res;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            TreeNode* tmp = treeStack.top();
            res.push_back(tmp->val);
            treeStack.pop();
            if (tmp->right) treeStack.push(tmp->right);
            if (tmp->left) treeStack.push(tmp->left);
        }

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (50.48%)
 * Likes:    1174
 * Dislikes: 63
 * Total Accepted:    301.4K
 * Total Submissions: 592.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return vector<int>();

        vector<int> res;
        stack<TreeNode*> stk;

        stk.push(root);
        while (!stk.empty()) {
            auto cur = stk.top();
            res.push_back(cur->val);
            stk.pop();
            if (cur->left) stk.push(cur->left);
            if (cur->right) stk.push(cur->right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

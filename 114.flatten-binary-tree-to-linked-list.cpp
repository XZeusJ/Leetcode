/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (44.44%)
 * Likes:    2140
 * Dislikes: 273
 * Total Accepted:    298K
 * Total Submissions: 644.6K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
   private:
    TreeNode* last = NULL;

   public:
    void
    flatten(TreeNode* root) {
        if (root == NULL) return;

        // 前序遍历
        // 注意更新last节点, 包括更新左右子树
        if (last != NULL) {
            last->left = NULL;
            last->right = root;
        }
        last = root;
        // 注意备份右子节点, 规避下一节点篡改
        TreeNode* copyRight = root->right;
        flatten(root->left);
        flatten(copyRight);
    }
};
// @lc code=end
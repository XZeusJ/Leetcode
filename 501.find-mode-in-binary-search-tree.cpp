/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (40.28%)
 * Likes:    737
 * Dislikes: 286
 * Total Accepted:    73.8K
 * Total Submissions: 179.5K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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

    int curCnt = 1;
    int preMax = 0;
    vector<int> res;
    TreeNode* pre = NULL;
    
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);

        if (pre) curCnt = root->val == pre->val ? curCnt + 1 : 1;
        if (curCnt == preMax) res.push_back(root->val);
        if (curCnt > preMax) {
            res.clear();
            res.push_back(root->val);
            preMax = curCnt;
        }
        pre = root;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if (!root) return res;
        inorder(root);
        return res;
    }
};
// @lc code=end

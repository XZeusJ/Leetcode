/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (35.97%)
 * Likes:    1036
 * Dislikes: 590
 * Total Accepted:    365.5K
 * Total Submissions: 999.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        // 叶子节点的定义是左孩子和右孩子都为 null 时叫做叶子节点
        // 1.当 root 节点左右孩子都为空时，即到达叶子节点, 返回 1
        if (root->left == NULL && root->right == NULL)
            return 1;
        // 2.当 root 节点左右孩子有一个为空时，返回不为空的孩子节点的深度
        // 解释: 当前节点左右子树有一个为空时，返回的应是非空子树的最小深度，而不是空子树深度0；
        // 若返回0相当于把当前节点认为成叶子节点，与此节点有非空子树矛盾。
        // 左孩子为空，只考虑右孩子的方向
        if (root->left == NULL) {
            return minDepth(root->right) + 1;
        }
        // 右孩子为空，只考虑左孩子的方向
        if (root->right == NULL) {
            return minDepth(root->left) + 1;
        }
        // 3.既有左孩子又有右孩子，那么就选一个较小的
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
// @lc code=end

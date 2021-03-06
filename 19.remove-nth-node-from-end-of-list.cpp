/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.61%)
 * Likes:    2297
 * Dislikes: 174
 * Total Accepted:    478.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *node = head, *offsetNode = head;
        for (int i = 0; i < n; ++i)
            node = node->next;

        // if node is NULL n is equal to the length of the linked list and we have to remove the head
        if (node == NULL)
            return head->next;

        while (node->next != NULL) {
            node       = node->next;
            offsetNode = offsetNode->next;
        }

        offsetNode->next = offsetNode->next->next;

        return head;
    }
};
// @lc code=end

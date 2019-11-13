/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (36.18%)
 * Likes:    1566
 * Dislikes: 109
 * Total Accepted:    224.5K
 * Total Submissions: 615.3K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;

        for (int i = 0; i < m - 1; i++) pre = pre->next;  // get first required point
        ListNode *cur = pre->next;
        for (int i = m; i < n; i++) {
            ListNode *t = cur->next;  // break down t and former relation
            cur->next   = t->next;    // breakdown 2 and 3, realte 2 to 4
            t->next     = pre->next;  // put 3 after 1
            pre->next   = t;          // breakdown 1 and 2, relate 1 to 3
        }
        return dummy->next;
    }
};
// @lc code=end

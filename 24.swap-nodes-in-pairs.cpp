/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (46.58%)
 * Likes:    1495
 * Dislikes: 136
 * Total Accepted:    373.1K
 * Total Submissions: 793.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;

        while (pre->next && pre->next->next) {
            ListNode* t     = pre->next->next;
            pre->next->next = t->next;
            t->next         = pre->next;
            pre->next       = t;

            pre = t->next;
        }
        return dummy->next;
    }
};
// @lc code=end

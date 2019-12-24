/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (38.11%)
 * Likes:    1573
 * Dislikes: 308
 * Total Accepted:    222.6K
 * Total Submissions: 572.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 2 functions
        // one for seperating list
        // one for reversing list

        /*
        -1->1->2->3->4->5
        |        |  |
        pre      cur next

        -1->3->2->1->4->5
            |     |  |
        cur   pre next
        */

        if (!head || k == 1) return head;
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = head;
        dummy->next = head;

        for (int i = 1; cur; i++) {
            if (i % k == 0) {
                pre = reverseOneGroup(pre, cur->next);
                cur = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }

    ListNode* reverseOneGroup(ListNode* pre, ListNode* next) {
        ListNode *last = pre->next, *cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next  = pre->next;
            pre->next  = cur;
            cur        = last->next;
        }
        return last;
    }
};
// @lc code=end

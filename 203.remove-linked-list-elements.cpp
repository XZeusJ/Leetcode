/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (36.52%)
 * Likes:    1272
 * Dislikes: 73
 * Total Accepted:    292.3K
 * Total Submissions: 784.8K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next     = head;

        ListNode *pre = dummy, *del;
        while (pre->next) {
            if (pre->next->val == val) {
                del       = pre->next;
                pre->next = pre->next->next;
                delete del;
            } else
                pre = pre->next;
        }
        return dummy->next;
    }
};
// @lc code=end

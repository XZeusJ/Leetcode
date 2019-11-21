/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.92%)
 * Likes:    6405
 * Dislikes: 1672
 * Total Accepted:    1.1M
 * Total Submissions: 3.4M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // special case:
        // 1. diff length
        // 2. only 0
        // 3. highest carry
        int curNum = 0, carry = 0, digit = 0;
        ListNode* res, head;
        head = res;
        
        while (l1 || l2) {
            if (l1 && l2) curNum = l1->val + l2->val;
            else if (l1) curNum = l1->val;
            else curNum = l2->val;
            curNum += carry
            digit = curNum % 10;
            
            res->val = digit;
            res = res->next;
                        
            carry = curNum / 10;
        }
        
        return head;
    }
};
// @lc code=end


// https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        if (l1 != nullptr) {
            if (l2 == nullptr) {
                head = l1;
            }
            else if (l1->val <= l2->val) {
                head = l1;
                head->next = mergeTwoLists(l1->next, l2);
            }
            else {
                head = l2;
                head->next = mergeTwoLists(l1, l2->next);
            }
        }
        else if (l2 != nullptr) {
            head = l2;
        }
        return head;
    }
};
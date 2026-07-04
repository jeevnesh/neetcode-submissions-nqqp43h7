/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = carry + l1->val + l2->val;
            if (sum / 10 > 0) {
                carry = sum / 10;
            }else{
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum % 10);
            l1 = l1->next;
            l2 = l2->next;
            temp->next = newNode;
            temp = newNode;
        }
        while (l1 != nullptr) {
            int sum = carry + l1->val;
            if (sum / 10 > 0) {
                carry = sum / 10;
            }else{
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum % 10);
            l1 = l1->next;
            temp->next = newNode;
            temp = newNode;
        }
        while (l2 != nullptr) {
            int sum = carry + l2->val;
            if (sum / 10 > 0) {
                carry = sum / 10;
            }else{
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum % 10);
            l2 = l2->next;
            temp->next = newNode;
            temp = newNode;
        }
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = newNode;
        }
        return dummy->next;
    }
};

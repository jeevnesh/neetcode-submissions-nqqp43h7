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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //find the size of LL
        ListNode* temp1 = head;
        int size = 0;
        while(temp1 != nullptr){
            temp1 = temp1->next;
            size++;
        }
        //remove nth node from end means remove size-n+1 from start
        // so take the temp pointer till size-n and make it's next pointer to it's next->next
        if(size - n == 0) return head->next;
        ListNode* temp2 = head;
        int pos = size-n-1;
        while(pos){
            temp2 = temp2->next;
            pos--;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};

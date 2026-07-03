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
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void mergeList(ListNode* head, ListNode* newHead){
        ListNode* curr1 = head;
        ListNode* next1;
        ListNode* curr2 = newHead;
        ListNode* next2;
        while(curr1 != nullptr && curr2 != nullptr){
            next1 = curr1->next;
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = next1;
            curr2 = next2;
        }
    }
public:
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr){
            temp = temp->next;
            size++;
        }
        int n = size%2 == 0 ? size/2-1 : size/2;
        ListNode* p1 = head;
        while(n){
            p1 = p1->next;
            n--;
        }
        ListNode* list2 = p1->next;
        p1->next = nullptr;
        //reverse the second half
        ListNode* newHead = reverse(list2);
        //merge list1 & list2 alternatively
        mergeList(head,newHead);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node* temp = head;
        while (temp != nullptr) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        temp = head;
        while (temp != nullptr) {
            if (temp->random != nullptr) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node* dummy = head->next;
        temp = head;
        while (temp != nullptr) {
            Node* ptr = temp->next;
            if (ptr != nullptr) {
                temp->next = ptr->next;
            }
            if (temp->next != nullptr) {
                ptr->next = temp->next->next;
            }
            temp = temp->next;
        }
        return dummy;
    }
};

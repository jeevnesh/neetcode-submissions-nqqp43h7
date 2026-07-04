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
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[nullptr] = nullptr;
        Node* temp = head;
        Node* dummy = new Node(0);
        Node* dummyPtr = dummy;
        while (temp != nullptr) {
            Node* newNode = new Node(temp->val);
            nodeMap[temp] = newNode;
            dummyPtr->next = newNode;
            dummyPtr = dummyPtr->next;
            temp = temp->next;
        }
        temp = head;
        dummyPtr = dummy->next;
        while (temp != nullptr) {
            dummyPtr->random = nodeMap[temp->random];
            temp = temp->next;
            dummyPtr = dummyPtr->next;
        }
        return dummy->next;
    }
};

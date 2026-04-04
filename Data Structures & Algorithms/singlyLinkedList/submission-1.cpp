class Node {
    private:
        int data;
        Node* next;
    public:
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
        int getData() {
            return data;
        }
        Node* getNext() {
            return next;
        }
        void setNext(Node* newNode) {
            next = newNode;
        }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* temp = head;
        int i = 0;
        while(temp != nullptr){
            if(i == index){
                return temp->getData();
            }
            i++;
            temp = temp->getNext();
        }
        return -1; 
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->setNext(head);
        head = newNode;
    }
    
    void insertTail(int val) {
        if(head == nullptr){
            head = new Node(val);
            return;
        }
        Node* temp = head;
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
        }
        Node* newNode = new Node(val);
        temp->setNext(newNode);
    }

    bool remove(int index) {
        if (head == nullptr) return false;  // Empty list check

        if (index == 0) {  // Special case: Removing the head node
            Node* temp = head;
            head = head->getNext();
            delete temp;
            return true;
        }
        Node* temp = head;
        int i = 0;
        while(temp != nullptr && temp->getNext() != nullptr){
            if(i == index-1){
                Node* nodeToRemove = temp->getNext();
                temp->setNext(nodeToRemove->getNext());
                delete nodeToRemove;
                return true;
            }
            i++;
            temp = temp->getNext();
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> ans;
        Node* temp = head;
        while(temp != nullptr){
            ans.push_back(temp->getData());
            temp = temp->getNext();
        }
        return ans;
    }
};

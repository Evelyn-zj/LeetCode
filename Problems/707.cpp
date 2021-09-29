class MyLinkedList {
public:
    struct Node{
        int val;
        Node* prev;
        Node* next;
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        first = nullptr;
        last = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* current;
        current = first;
        if (current == nullptr) {
            return -1;
        }
        while (current->next != nullptr && index > 0) {
            current = current->next;
            index--;
        }
        if (index > 0) {
            return -1;
        } else {
            return current->val;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* current;
        current = new Node;
        current->val = val;
        current->prev = nullptr;
        if (first == nullptr) {
            current->next = nullptr;
            first = current;
            last = current;
        } else {
            first->prev = current;
            current->next = first;
            first = current;
        }
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* current;
        current = new Node;
        current->val = val;
        current->next = nullptr;
        if (first == nullptr) {
            current->prev = nullptr;
            first = current;
            last = current;
        } else {
            last->next = current;
            current->prev = last;
            last = current;
        }
        return;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node *front, *back, *current;
        back = first;
        if (back == nullptr && index == 0) {
            current = new Node;
            current->val = val;
            current->prev = nullptr;
            current->next = nullptr;
            first = current;
            last = current;
            return;
        } else if (back == nullptr) {
            return;
        }
        while (back->next != nullptr && index > 0) {
            back = back->next;
            index--;
        }
        if (index == 0) {
            if (back->prev == nullptr) {
                current = new Node;
                current->val = val;
                current->prev = nullptr;
                current->next = back;
                back->prev = current;
                first = current;
            } else {
                front = back->prev;
                current = new Node;
                current->val = val;
                current->prev = front;
                current->next = back;
                front->next = current;
                back->prev = current;
            }
        } else if (index == 1) {
            current = new Node;
            current->val = val;
            current->prev = back;
            current->next = nullptr;
            back->next = current;
            last = current;
        }
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node *current, *front, *back;
        current = first;
        if (current == nullptr) {
            return;
        }
        while (current->next != nullptr && index > 0) {
            current = current->next;
            index--;
        }
        if (index == 0) {
            if (current->prev == nullptr && current->next == nullptr) {
                first = nullptr;
                last = nullptr;
            } else if (current->prev == nullptr) {
                first = first->next;
                first->prev = nullptr;
            } else if (current->next == nullptr) {
                last = last->prev;
                last->next = nullptr;
            } else {
                front = current->prev;
                back = current->next;
                front->next = back;
                back->prev = front;
            }
            delete current;
        }
    }

private:
    Node* first;
    Node* last;
};
#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head; // Point to itself to make it circular
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
    }

    void display() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(4);
    list.insert(5);
    list.insert(8);
    list.insert(9);
    list.insert(13);
    list.insert(14);
    list.insert(18);
    list.insert(20);

    // Make the node 20 point to node 4 to make it circular
    Node* temp = list.head;
    while (temp->next != list.head) {
        temp = temp->next;
    }
    temp->next = list.head;

    list.display();

    return 0;
}

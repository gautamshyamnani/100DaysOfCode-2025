#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};


Node* deleteNode(Node* head, int x) {
    
    if (head == nullptr) return nullptr;

    if (x == 1) {
        Node* temp = head;
        head = head->next;
        delete temp; 
        return head;
    }

    
    Node* current = head;
    for (int i = 1; i < x - 1 && current != nullptr; i++) {
        current = current->next;
    }

   
    if (current == nullptr || current->next == nullptr) return head;

    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next; 
    delete nodeToDelete;

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(9);

    cout << "Original List: ";
    printList(head);

    int x = 2; 
    head = deleteNode(head, x);

    cout << "After Deleting Position " << x << ": ";
    printList(head);

    return 0;
}

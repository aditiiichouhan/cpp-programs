#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(Node*& head, int key) {
    if (!head) return;
    Node* temp = head;
    if (head->data == key) {
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
    }
    while (temp && temp->data != key) {
        temp = temp->next;
    }
    if (temp) {
        temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }
}

void traverseForward(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void traverseBackward(Node* head) {
    if (!head) return;
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);
    traverseForward(head);

    deleteNode(head, 20);
    traverseForward(head);

    insertAtEnd(head, 30);
    traverseForward(head);
    traverseBackward(head);

    return 0;
}
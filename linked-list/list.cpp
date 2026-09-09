#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* buildList() {
    int n;
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node *newNode = new Node(x);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

Node* deleteNode(Node *head, int x) {
    if (head == nullptr) return nullptr;

    if (head->data == x) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *curr = head;
    while (curr->next != nullptr && curr->next->data != x) {
        curr = curr->next;
    }

    if (curr->next != nullptr) {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    return head;
}

Node* insertNode(Node *head, int index, int x) {
    Node *newNode = new Node(x);

    if (index == 0) {
        newNode->next = head;
        return newNode;
    }

    Node *curr = head;
    for (int i = 0; i < index - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        delete newNode;
        return head;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

Node* reverseList(Node *head) {
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr) {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head = buildList();

    head = insertNode(head, 2, 99);
    printList(head);

    head = deleteNode(head, 99);
    printList(head);

    head = reverseList(head);
    printList(head);

    return 0;
}

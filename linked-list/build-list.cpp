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

void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head = buildList();
    printList(head);
    return 0;
}

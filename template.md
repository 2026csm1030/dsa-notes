# 1. Linked List Template

This is the one you should be most comfortable with because almost every linked-list question modifies one of these operations.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Insert at beginning
Node* insertAtBeginning(Node* head, int x) {
    Node* newNode = new Node(x);

    newNode->next = head;
    head = newNode;

    return head;
}

// Insert at end
Node* insertAtEnd(Node* head, int x) {
    Node* newNode = new Node(x);

    if (head == nullptr)
        return newNode;

    Node* curr = head;

    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newNode;

    return head;
}

// Delete first occurrence of x
Node* deleteNode(Node* head, int x) {
    if (head == nullptr)
        return nullptr;

    // If head itself needs to be deleted
    if (head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;

    while (curr->next != nullptr &&
           curr->next->data != x) {
        curr = curr->next;
    }

    if (curr->next != nullptr) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    return head;
}

// Search
bool search(Node* head, int x) {
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data == x)
            return true;

        curr = curr->next;
    }

    return false;
}

// Length
int length(Node* head) {
    int count = 0;
    Node* curr = head;

    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }

    return count;
}

// Print
void printList(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
}
```

### Most important pointer pattern

For traversal:

```cpp
Node* curr = head;

while (curr != nullptr) {
    // work
    curr = curr->next;
}
```

For changing links:

```cpp
curr->next = something;
```

### Your essential linked-list toolkit

```text
Traversal       → curr
Insertion       → newNode
Deletion        → temp
Reversal        → prev, curr, next
Kth from end    → slow, fast
Cycle           → slow, fast
```

---

# 2. Stack Template — Without STL

We'll implement a stack using an array.

```cpp
class Stack {
private:
    int arr[1000];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 999;
    }

    void push(int x) {
        if (isFull())
            return;

        topIndex++;
        arr[topIndex] = x;
    }

    void pop() {
        if (isEmpty())
            return;

        topIndex--;
    }

    int top() {
        if (isEmpty())
            return -1;

        return arr[topIndex];
    }

    int size() {
        return topIndex + 1;
    }
};
```

Usage:

```cpp
Stack st;

st.push(10);
st.push(20);
st.push(30);

cout << st.top() << endl;  // 30

st.pop();

cout << st.top() << endl;  // 20
```

---

## The only things you really need to remember

```text
Empty:
topIndex == -1

Push:
++topIndex
arr[topIndex] = x

Pop:
--topIndex

Top:
arr[topIndex]
```

Visualize it:

```text
       top
        ↓
     +-----+
     | 30  |
     +-----+
     | 20  |
     +-----+
     | 10  |
     +-----+
```

---

# 3. Queue Template — Without STL

We'll use an array-based **circular queue** because it's the proper general implementation.

```cpp
class Queue {
private:
    int arr[1000];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == 1000;
    }

    void enqueue(int x) {
        if (isFull())
            return;

        rearIndex = (rearIndex + 1) % 1000;
        arr[rearIndex] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty())
            return;

        frontIndex = (frontIndex + 1) % 1000;
        count--;
    }

    int front() {
        if (isEmpty())
            return -1;

        return arr[frontIndex];
    }

    int size() {
        return count;
    }
};
```

Usage:

```cpp
Queue q;

q.enqueue(10);
q.enqueue(20);
q.enqueue(30);

cout << q.front() << endl;  // 10

q.dequeue();

cout << q.front() << endl;  // 20
```

---

## Queue mental model

```text
             front             rear
               ↓                ↓
            +----+----+----+----+
            | 10 | 20 | 30 |    |
            +----+----+----+----+
```

### Enqueue

Add at:

```text
rear
```

### Dequeue

Remove from:

```text
front
```

Therefore:

```text
Queue = FIFO
```

---

# 4. Binary Tree / BST Template

This one is particularly important because your professor's second practice set is heavily focused on trees/BSTs. 

## Node

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
```

---

## BST Insert

```cpp
Node* insert(Node* root, int x) {
    if (root == nullptr)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);

    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}
```

Usage:

```cpp
Node* root = nullptr;

root = insert(root, 50);
root = insert(root, 30);
root = insert(root, 70);
root = insert(root, 20);
root = insert(root, 40);
```

Produces:

```text
        50
       /  \
     30    70
    / \
   20 40
```

---

# 5. Tree Traversals

### Inorder

```cpp
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}
```

### Preorder

```cpp
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}
```

### Postorder

```cpp
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}
```

### Remember

```text
Inorder:
LEFT → ROOT → RIGHT

Preorder:
ROOT → LEFT → RIGHT

Postorder:
LEFT → RIGHT → ROOT
```

For a BST:

> **Inorder = sorted order.**

That's why your professor can ask things like **kth smallest** and **pair sum** using inorder traversal. 

---

# 6. BST Search

```cpp
bool search(Node* root, int x) {
    if (root == nullptr)
        return false;

    if (root->data == x)
        return true;

    if (x < root->data)
        return search(root->left, x);

    return search(root->right, x);
}
```

---

# 7. Tree Height

```cpp
int height(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}
```

Notice that I **didn't use `max()`** because we're assuming library functions aren't allowed.

---

# 8. Count Nodes

```cpp
int countNodes(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 +
           countNodes(root->left) +
           countNodes(root->right);
}
```

---

# 9. Count Leaves

```cpp
int countLeaves(Node* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr &&
        root->right == nullptr)
        return 1;

    return countLeaves(root->left) +
           countLeaves(root->right);
}
```

---

# 10. Find Minimum in BST

```cpp
int findMin(Node* root) {
    if (root == nullptr)
        return -1;

    Node* curr = root;

    while (curr->left != nullptr)
        curr = curr->left;

    return curr->data;
}
```

And maximum:

```cpp
int findMax(Node* root) {
    if (root == nullptr)
        return -1;

    Node* curr = root;

    while (curr->right != nullptr)
        curr = curr->right;

    return curr->data;
}
```

---

# 11. Your BST Delete Template

This is the one we just learned:

```cpp
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // No child
        if (root->left == nullptr &&
            root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Only right child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Only left child
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        Node* successor = root->right;

        while (successor->left != nullptr)
            successor = successor->left;

        root->data = successor->data;

        root->right =
            deleteNode(root->right, successor->data);
    }

    return root;
}
```

### One improvement over our earlier version

Here we're actually doing:

```cpp
delete root;
```

when removing a node.

That's good C++ practice and avoids a memory leak.

---

# 12. 🚨 What NOT to use in your lab

Given your professor's instruction, for our preparation I'd avoid all of these:

```cpp
vector
list
stack
queue
sort()
reverse()
max()
min()
swap()
find()
```

Also avoid relying on convenience functions when you can implement the operation yourself.

For example:

### ❌

```cpp
sort(arr, arr + n);
```

### ✅

Write your own sorting algorithm.

---

# 13. What you CAN comfortably use

These are fundamental C++ constructs:

```cpp
if
else
for
while
switch

struct
class

new
delete

int
char
bool

arrays
pointers

cin
cout
```

And operators:

```cpp
+
-
*
/
%
==
!=
<
>
<=
>=
```

The key distinction is:

> **Don't let the library do the algorithm for you.**

---

# 14. One important thing about `iostream`

Technically:

```cpp
#include <iostream>
```

is a standard library header.

But unless your professor literally wants you to implement input/output, **they obviously must be allowing basic I/O** or providing their own input framework.

So I would continue using:

```cpp
cin
cout
```

while avoiding algorithm/data-structure library functions.

---

# 15. Your "Lab Template" cheat sheet

If you have to remember only the essentials:

### Linked List

```cpp
struct Node {
    int data;
    Node* next;
};
```

Traversal:

```cpp
Node* curr = head;

while (curr != nullptr) {
    // ...
    curr = curr->next;
}
```

---

### Stack

```text
topIndex = -1

push:
++topIndex
arr[topIndex] = x

pop:
--topIndex

top:
arr[topIndex]
```

---

### Queue

```text
front
rear
count

enqueue → rear
dequeue → front
```

---

### Tree

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

Recursive template:

```cpp
if (root == nullptr)
    return;

solve(root->left);

// process root

solve(root->right);
```

---

### BST

```text
x < root → LEFT

x > root → RIGHT
```

And:

```text
Inorder → sorted
```

---


For the remaining preparation, I'll use **these no-STL templates** in every solution. That way you're practicing in exactly the style you need for the test.

# C++ DSA Lab Reference Manual

## 1. Basic C++ Skeleton

```cpp
#include <iostream>
using namespace std;

int main() {
    // code

    return 0;
}
```

### Input / Output

```cpp
int n;
cin >> n;

cout << n << endl;
```

Multiple values:

```cpp
int a, b;
cin >> a >> b;

cout << a << " " << b << endl;
```

---

# 2. Arrays

### Declaration

```cpp
int arr[1000];
```

Input:

```cpp
for (int i = 0; i < n; i++)
    cin >> arr[i];
```

Output:

```cpp
for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
```

### Swap without `swap()`

```cpp
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
```

### Manual maximum

```cpp
int maximum(int a, int b) {
    if (a > b)
        return a;
    return b;
}
```

### Manual minimum

```cpp
int minimum(int a, int b) {
    if (a < b)
        return a;
    return b;
}
```

---

# 3. Useful Array Patterns

### Reverse

```cpp
int i = 0;
int j = n - 1;

while (i < j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    i++;
    j--;
}
```

### Linear Search

```cpp
bool found = false;

for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
        found = true;
        break;
    }
}
```

### Bubble Sort — if sorting is required

```cpp
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}
```

---

# 4. Pointers

### Declaration

```cpp
int* p;
```

### Address

```cpp
p = &x;
```

### Dereference

```cpp
*p
```

### Struct pointer

```cpp
Node* curr;
```

Access members:

```cpp
curr->data;
curr->next;
```

Remember:

```text
normal object → .
pointer       → ->
```

---

# 5. Linked List

## Node

```cpp
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
```

## Create Node

```cpp
Node* newNode = new Node(x);
```

## Traverse

```cpp
Node* curr = head;

while (curr != nullptr) {
    cout << curr->data << " ";
    curr = curr->next;
}
```

## Insert at Beginning

```cpp
Node* newNode = new Node(x);

newNode->next = head;
head = newNode;
```

## Insert at End

```cpp
Node* newNode = new Node(x);

if (head == nullptr) {
    head = newNode;
}
else {
    Node* curr = head;

    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newNode;
}
```

## Delete First Node

```cpp
if (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
}
```

---

# 6. Linked List Patterns

### Reverse

```cpp
Node* prev = nullptr;
Node* curr = head;

while (curr != nullptr) {
    Node* next = curr->next;

    curr->next = prev;

    prev = curr;
    curr = next;
}

head = prev;
```

**Remember:**

```text
SAVE → REVERSE → MOVE
```

---

### Kth From End

```cpp
Node* slow = head;
Node* fast = head;

for (int i = 0; i < k; i++) {
    if (fast == nullptr)
        return nullptr;

    fast = fast->next;
}

while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;
}

return slow;
```

**Remember:**

```text
Move fast k steps
→ move both together
→ slow = answer
```

---

### Middle Node

```cpp
Node* slow = head;
Node* fast = head;

while (fast != nullptr &&
       fast->next != nullptr) {

    slow = slow->next;
    fast = fast->next->next;
}

return slow;
```

---

### Cycle Detection

```cpp
Node* slow = head;
Node* fast = head;

while (fast != nullptr &&
       fast->next != nullptr) {

    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
        return true;
}

return false;
```

---

# 7. Stack — Without STL

```cpp
class Stack {
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
        if (!isFull()) {
            topIndex++;
            arr[topIndex] = x;
        }
    }

    void pop() {
        if (!isEmpty())
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

### Stack mental model

```text
push → top
pop  → top

LIFO
```

---

# 8. Queue — Without STL

Circular queue:

```cpp
class Queue {
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

### Queue mental model

```text
enqueue → rear
dequeue → front

FIFO
```

---

# 9. Stack/Queue Useful Patterns

### Move Queue → Stack

```cpp
while (!q.isEmpty()) {
    st.push(q.front());
    q.dequeue();
}
```

### Move Stack → Queue

```cpp
while (!st.isEmpty()) {
    q.enqueue(st.top());
    st.pop();
}
```

### Rotate Queue

```cpp
int x = q.front();
q.dequeue();
q.enqueue(x);
```

---

# 10. Binary Tree / BST

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

---

## BST Search

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

# 11. Tree Traversals

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
Inorder   → LEFT ROOT RIGHT
Preorder  → ROOT LEFT RIGHT
Postorder → LEFT RIGHT ROOT
```

**BST:**

```text
Inorder → sorted order
```

---

# 12. Tree Recursion Template

Most tree problems follow:

```cpp
ReturnType solve(Node* root) {

    if (root == nullptr)
        return baseValue;

    ReturnType left =
        solve(root->left);

    ReturnType right =
        solve(root->right);

    // combine left, right and root

    return result;
}
```

# 13. Tree Height

```cpp
int height(Node* root) {
    if (root == nullptr)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if (left > right)
        return left + 1;

    return right + 1;
}
```

---

# 14. Count Nodes

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

# 15. Count Leaves

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

# 16. BST Minimum / Maximum

### Minimum

```cpp
Node* curr = root;

while (curr->left != nullptr)
    curr = curr->left;

return curr->data;
```

### Maximum

```cpp
Node* curr = root;

while (curr->right != nullptr)
    curr = curr->right;

return curr->data;
```

---

# 17. BST Delete

```cpp
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (key < root->data) {
        root->left =
            deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right =
            deleteNode(root->right, key);
    }
    else {

        // 0 children
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

        // 2 children
        Node* successor = root->right;

        while (successor->left != nullptr)
            successor = successor->left;

        root->data = successor->data;

        root->right =
            deleteNode(root->right,
                       successor->data);
    }

    return root;
}
```

### Remember

```text
0 child → NULL
1 child → return child
2 child → inorder successor
```

---

# 18. LCA of BST

```cpp
Node* LCA(Node* root, int p, int q) {

    while (root != nullptr) {

        if (p < root->data &&
            q < root->data) {

            root = root->left;
        }
        else if (p > root->data &&
                 q > root->data) {

            root = root->right;
        }
        else {
            return root;
        }
    }

    return nullptr;
}
```

### Remember

```text
both smaller → LEFT
both larger  → RIGHT
otherwise    → ANSWER
```

---

# 19. Kth Smallest in BST

Simple recursive version:

```cpp
void inorder(Node* root,
             int k,
             int& count,
             int& answer) {

    if (root == nullptr)
        return;

    inorder(root->left, k, count, answer);

    count++;

    if (count == k) {
        answer = root->data;
        return;
    }

    inorder(root->right, k, count, answer);
}
```

Main idea:

```text
BST
 ↓
Inorder
 ↓
Sorted
 ↓
kth visited = kth smallest
```

---

# 20. No-STL Rules

```cpp
vector
stack
queue
list

sort()
reverse()
max()
min()
swap()
find()
```

Instead:

```text
vector → array
stack  → your Stack class
queue  → your Queue class
sort   → implement sorting
max    → if/else
min    → if/else
swap   → temporary variable
```

---

# 21. C++ Things Most Likely to Trip You Up

### Pointer member access

```cpp
curr->next
curr->data
root->left
```

### Reference parameter

```cpp
int& count
```

Use when a function needs to modify the original variable.

### Dynamic memory

```cpp
Node* x = new Node(10);

delete x;
```

### Null pointer

```cpp
nullptr
```

Check before dereferencing:

```cpp
if (curr != nullptr)
    cout << curr->data;
```

---

# 22. Your Last-Minute Mental Cheat Sheet

```text
ARRAY
→ arr[i]

LINKED LIST
→ Node*
→ curr->next

REVERSE LIST
→ prev, curr, next
→ SAVE → REVERSE → MOVE

KTH FROM END
→ slow + fast
→ fast k ahead

MIDDLE
→ slow + fast
→ fast moves 2x

CYCLE
→ slow + fast
→ if slow == fast

STACK
→ topIndex
→ push / pop / top
→ LIFO

QUEUE
→ front / rear / count
→ enqueue / dequeue
→ FIFO

TREE
→ nullptr base case
→ recursion

INORDER
→ LEFT ROOT RIGHT

BST
→ smaller = LEFT
→ larger = RIGHT

BST INORDER
→ SORTED

BST DELETE
→ 0 child / 1 child / 2 children

LCA BST
→ both left / both right / otherwise root

KTH SMALLEST BST
→ inorder + count
```

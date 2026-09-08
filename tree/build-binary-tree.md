Yes. For a **general binary tree**, a common terminal-input method is to enter nodes in **preorder**, using `-1` to represent `NULL`.

### Example input

For this tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

Input:

```text
1 2 4 -1 -1 5 -1 -1 3 -1 -1
```

### C++ — Build Tree from Terminal

```cpp
#include <iostream>
using namespace std;

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

Node* buildTree() {
    int x;
    cin >> x;

    // -1 means NULL
    if (x == -1)
        return nullptr;

    Node* root = new Node(x);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL): ";

    Node* root = buildTree();

    cout << "Inorder: ";
    inorder(root);

    return 0;
}
```

### How `buildTree()` works

For input:

```text
1 2 4 -1 -1 5 -1 -1 3 -1 -1
```

The recursive calls construct:

| Input   | Meaning           |
| ------- | ----------------- |
| `1`     | Root              |
| `2`     | Left child of 1   |
| `4`     | Left child of 2   |
| `-1`    | 4's left = NULL   |
| `-1`    | 4's right = NULL  |
| `5`     | Right child of 2  |
| `-1 -1` | 5 has no children |
| `3`     | Right child of 1  |
| `-1 -1` | 3 has no children |

So the output is:

```text
Inorder: 4 2 5 1 3
```

**Important for your lab:** this uses only `iostream`; no STL containers or built-in algorithms.



Yes. If the binary tree is given in **level order**, the easiest way is to use a **queue**.

For example, input:

```text
1 2 3 4 5 -1 6 -1 -1 7 8
```

represents:

```text
        1
       / \
      2   3
     / \   \
    4   5   6
       / \
      7   8
```

Here `-1` means **NULL**.

### C++ — Build Binary Tree from Level Order

Since your professor doesn't allow STL, we'll implement our **own queue** using an array.

```cpp
#include <iostream>
using namespace std;

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

class Queue {
    Node* arr[1000];
    int frontIndex;
    int rearIndex;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
    }

    bool isEmpty() {
        return frontIndex > rearIndex;
    }

    void enqueue(Node* x) {
        rearIndex++;
        arr[rearIndex] = x;
    }

    Node* dequeue() {
        if (isEmpty())
            return nullptr;

        return arr[frontIndex++];
    }
};

Node* buildTree() {
    int x;
    cin >> x;

    // Empty tree
    if (x == -1)
        return nullptr;

    Node* root = new Node(x);

    Queue q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        Node* current = q.dequeue();

        // Left child
        cin >> x;

        if (x != -1) {
            current->left = new Node(x);
            q.enqueue(current->left);
        }

        // Right child
        cin >> x;

        if (x != -1) {
            current->right = new Node(x);
            q.enqueue(current->right);
        }
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "Enter level order (-1 for NULL): ";

    Node* root = buildTree();

    cout << "Inorder: ";
    inorder(root);

    return 0;
}
```

### Dry run

Input:

```text
1 2 3 4 5 -1 6 -1 -1 7 8
```

The queue works like this:

| Current node | Left | Right | Queue after processing |
| ------------ | ---: | ----: | ---------------------- |
| `1`          |  `2` |   `3` | `2, 3`                 |
| `2`          |  `4` |   `5` | `3, 4, 5`              |
| `3`          | `-1` |   `6` | `4, 5, 6`              |
| `4`          | `-1` |  `-1` | `5, 6`                 |
| `5`          |  `7` |   `8` | `6, 7, 8`              |
| `6`          | `-1` |  `-1` | `7, 8`                 |

### The key pattern to remember

For **level-order tree construction**:

```text
1. Read root
2. Put root in queue
3. While queue is not empty:
      remove one node
      read its left child
      read its right child
      add non-null children to queue
```

So the difference is:

```text
Preorder input  → recursion
Level-order     → queue
```

This is a **very important tree-building template for your lab test**.


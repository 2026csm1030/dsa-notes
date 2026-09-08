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

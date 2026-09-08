Yes. For a **Binary Search Tree (BST)**, you can take values from the terminal one by one and insert them according to the BST property:

* smaller → left
* larger → right

### C++ — Build BST from Terminal

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

Node* insert(Node* root, int x) {
    if (root == nullptr)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

Node* buildBST() {
    int n, x;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
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
    cout << "Enter number of nodes: ";

    Node* root = buildBST();

    cout << "Enter elements in BST order: ";

    cout << "Inorder: ";
    inorder(root);

    return 0;
}
```

### Example

Input:

```text
7
50 30 70 20 40 60 80
```

BST formed:

```text
        50
       /  \
     30    70
    / \    / \
   20 40  60 80
```

Inorder output:

```text
20 30 40 50 60 70 80
```

### Remember this for the lab

The **build BST pattern** is simply:

```cpp
root = nullptr;

for each input x:
    root = insert(root, x);
```

And the core insertion:

```cpp
if (root == nullptr)
    return new Node(x);

if (x < root->data)
    root->left = insert(root->left, x);
else if (x > root->data)
    root->right = insert(root->right, x);

return root;
```

**Complexity:** `O(h)` per insertion, so `O(nh)` for building `n` nodes. In a balanced BST, `O(n log n)`; worst case, `O(n²)`.

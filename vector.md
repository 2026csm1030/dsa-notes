## 1. Normal Queue using `vector`

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Queue {
    vector<int> arr;
    int frontIndex;

public:
    Queue() {
        frontIndex = 0;
    }

    void enqueue(int x) {
        arr.push_back(x);
    }

    void dequeue() {
        if (isEmpty()) return;
        frontIndex++;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    bool isEmpty() {
        return frontIndex == arr.size();
    }

    int size() {
        return arr.size() - frontIndex;
    }
};
```

### Key idea

```text
enqueue → push_back()
dequeue → move frontIndex
front   → arr[frontIndex]
```

---

# 2. Circular Queue using `vector`

Here we use a fixed-size vector.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
    vector<int> arr;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    CircularQueue(int n) {
        capacity = n;
        arr.resize(n);
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Full\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    int rear() {
        if (isEmpty()) return -1;
        return arr[rearIndex];
    }

    int size() {
        return count;
    }
};
```

genui{"learning_viz":{"type_id":"ARRAY_QUEUE_FRONT_REAR","initial_values":{"mode":"circular"}}}

### Most important part

```cpp
rearIndex = (rearIndex + 1) % capacity;
frontIndex = (frontIndex + 1) % capacity;
```

This is what makes it **circular**.

---

# 3. Build Binary Tree — Preorder Input

Input format:

```text
root left-subtree right-subtree
```

Use `-1` for NULL.

Example:

```text
1 2 4 -1 -1 5 -1 -1 3 -1 -1
```

### Code

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

    if (x == -1)
        return nullptr;

    Node* root = new Node(x);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}
```

### Pattern to memorize

```cpp
read x

if x == -1
    return NULL

create node

root->left = buildTree()
root->right = buildTree()

return root
```

**Complexity:** `O(n)` time, `O(h)` recursion stack.

---

# 4. Build Binary Tree — Level Order Input

For level order, use a queue.

Input:

```text
1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
```

### Code

```cpp
#include <iostream>
#include <vector>
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

    if (x == -1)
        return nullptr;

    Node* root = new Node(x);

    vector<Node*> q;
    q.push_back(root);

    int frontIndex = 0;

    while (frontIndex < q.size()) {
        Node* current = q[frontIndex++];

        // Left child
        cin >> x;

        if (x != -1) {
            current->left = new Node(x);
            q.push_back(current->left);
        }

        // Right child
        cin >> x;

        if (x != -1) {
            current->right = new Node(x);
            q.push_back(current->right);
        }
    }

    return root;
}
```

### Why `frontIndex`?

Instead of actually removing elements from the vector:

```cpp
q.erase(q.begin());
```

we simply move:

```cpp
frontIndex++;
```

So the vector acts like a queue:

```text
q = [1, 2, 3, 4, 5]

frontIndex
    ↓
    0   1   2   3   4
    1   2   3   4   5
```

This avoids repeatedly shifting the vector.

---

## 🧠 Four templates to remember

| Problem               | Main technique                     |
| --------------------- | ---------------------------------- |
| **Queue**             | `vector + frontIndex`              |
| **Circular Queue**    | `vector + front/rear + % capacity` |
| **Tree: Preorder**    | **Recursion**                      |
| **Tree: Level Order** | `vector<Node*> + frontIndex`       |

For your lab, I'd memorize these **four skeletons** rather than the complete programs. Most tree/queue questions can be built on top of them.

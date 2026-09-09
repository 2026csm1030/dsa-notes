#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int x)
  {
    data = x;
    left = nullptr;
    right = nullptr;
  }
};

class CircularQueue
{
private:
  Node *arr[100];
  int front;
  int rear;
  int size;

public:
  CircularQueue()
  {
    front = 0;
    rear = -1;
    size = 0;
  }

  bool isEmpty()
  {
    return size == 0;
  }

  bool isFull()
  {
    return size == 100;
  }

  void enqueue(Node *x)
  {
    if (isFull())
      return;

    rear = (rear + 1) % 100;
    arr[rear] = x;
    size++;
  }

  Node *dequeue()
  {
    if (isEmpty())
      return nullptr;

    Node *n = arr[front];

    front = (front + 1) % 100;
    size--;

    return n;
  }

  Node *getFront()
  {
    if (isEmpty())
      return nullptr;

    return arr[front];
  }

  Node *getRear()
  {
    if (isEmpty())
      return nullptr;

    return arr[rear];
  }

  int getSize()
  {
    return size;
  }
};

Node *buildTree()
{
  int x;
  cin >> x;

  if (x == -1)
    return nullptr;

  Node *root = new Node(x);

  CircularQueue q;
  q.enqueue(root);

  while (!q.isEmpty())
  {
    Node *curr = q.dequeue();

    // Left child
    cin >> x;

    if (x != -1)
    {
      curr->left = new Node(x);
      q.enqueue(curr->left);
    }

    // Right child
    cin >> x;

    if (x != -1)
    {
      curr->right = new Node(x);
      q.enqueue(curr->right);
    }
  }

  return root;
}

void inOrder(Node *root)
{
  if (root == nullptr)
    return;

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

int main()
{
  // input: 1 2 3 4 5 -1 6 -1 -1 7 8 -1 -1 -1 -1 -1 -1
  // output: 4 2 7 5 8 1 3 6
  
  Node *root = buildTree();

  cout << endl;

  inOrder(root);

  return 0;
}

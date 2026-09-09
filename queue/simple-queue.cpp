#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == 99;
    }

    void enqueue(int x) {
        if (isFull()) return;
        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        front++;
        return val;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getSize() {
        return rear - front + 1;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.getFront() << endl;
    cout << q.getSize() << endl;

    return 0;
}

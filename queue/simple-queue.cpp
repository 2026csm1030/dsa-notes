#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front;
    int rear;
    int size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == 100;
    }

    void enqueue(int x) {
        if (isFull()) return;
        rear = (rear + 1) % 100;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        front = (front + 1) % 100;
        size--;
        return val;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getSize() {
        return size;
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

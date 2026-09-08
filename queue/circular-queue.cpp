#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[100];
    int front;
    int rear;
    int size;

public:
    CircularQueue() {
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
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        rear = (rear + 1) % 100;
        arr[rear] = x;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        front = (front + 1) % 100;
        size--;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return arr[rear];
    }

    int getSize() {
        return size;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue();

    q.enqueue(40);

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    return 0;
}

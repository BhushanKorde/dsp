#include <iostream>
using namespace std;
#define MAX 10
int Q[MAX];
int front = -1;
int rear = -1;
int n;

void enqueueRear() {
    if ((rear + 1) % MAX == front) {  // Circular queue overflow check
        cout << "Queue Overflow\n";
    } else if (rear == -1) {
        rear = 0;
        front = 0;
        cout << "Enter the number: ";
        cin >> n;
        Q[rear] = n;
    } else {
        rear = (rear + 1) % MAX;
        cout << "Enter the number: ";
        cin >> n;
        Q[rear] = n;
    }
}

void dequeueFront() {
    if (front == -1) {
        cout << "Queue Underflow\n";
    } else if (front == rear) {  // Only one element in queue
        cout << Q[front] << " is deleted\n";
        rear = -1;
        front = -1;
    } else {
        cout << Q[front] << " is deleted\n";
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is Empty\n";
    } else {
        int i = front;
        while (i != rear) {
            cout << "\t" << Q[i] << "\t" << endl;
            i = (i + 1) % MAX;
        }
        cout << "\t" << Q[rear] << "\t" << endl;
    }
}

void enqueueFront() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {  // Queue is full
        cout << "Queue Overflow\n";
    } else if (front == -1) {  // If the queue is empty
        front = 0;
        rear = 0;
        cout << "Enter the number: ";
        cin >> n;
        Q[front] = n;
    } else {
        front = (front - 1 + MAX) % MAX;
        cout << "Enter the number: ";
        cin >> n;
        Q[front] = n;
    }
}

void dequeueRear() {
    if (rear == -1) {
        cout << "Queue Underflow\n";
    } else if (front == rear) {  // Only one element in queue
        cout << Q[rear] << " is deleted\n";
        rear = -1;
        front = -1;
    } else {
        cout << Q[rear] << " is deleted\n";
        rear = (rear - 1 + MAX) % MAX;
    }
}

int main() {
    int ch;
    do {
        cout << "Menu\n1.EnqueueRear\n2.DequeueFront\n3.EnqueueFront\n4.DequeueRear\n5.Display\n6.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                enqueueRear();
                break;
            case 2:
                dequeueFront();
                break;
            case 3:
                enqueueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
            default:
                cout << "Wrong Choice\n";
                break;
        }
    } while (ch != 6);
    return 0;
}

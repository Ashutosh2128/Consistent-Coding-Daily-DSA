#include<iostream>
using namespace std;

class Queue {
    int* arr;
    int n;
    int front;
    int rear;

    public:
    Queue(int size) {
        arr = new int(size);
        this -> n = size;
        this -> front = -1;
        this -> rear = -1;
    }

    void push(int val) {
        if(front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if(rear == n-1) cout << "Queue Overflow" << endl;
        else arr[++rear] = val;
    }

    void pop() {
        if(front == -1 && rear == -1) cout << "Queue Underflow" << endl;
        else if(front == rear) {
            arr[front] = 0;
            front = -1;
            rear = -1;
        }
        else arr[front++] = 0;
    }

    int getFront() {
        if(front == -1 && rear == -1) cout << "Queue is empty" << endl;
        else return arr[front];
    }

    int back() {
        if(front == -1 && rear == -1) cout << "Queue is empty" << endl;
        else return arr[rear];
    }

    int size() {
        if(front == -1 && rear == -1) return 0;
        else return rear - front + 1;
    }

    bool isEmpty() {
        if(front == -1 && rear == -1) return 1;
        else return 0;
    }

    void print() {
        for(int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q(6);

    q.push(1);
    q.print();
    q.push(2);
    q.print();
    q.push(3);
    q.print();
    q.push(4);
    q.print();
    q.push(5);
    q.print();
    q.push(6);
    q.print();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.isEmpty() << endl;

    q.pop();
    q.print();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.isEmpty() << endl;

    q.pop();
    q.print();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.isEmpty() << endl;

    q.pop();
    q.print();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.isEmpty() << endl;

    q.pop();
    q.print();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.isEmpty() << endl;

    q.pop();
    q.print();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.isEmpty() << endl;

    q.pop();
    q.print();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty: " << q.isEmpty() << endl;

    return 0;
}
#include<iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int n;
    int front;
    int rear;

    public:
        CircularQueue(int size) {
            arr = new int(size);
            this -> n = size;
            this -> front = -1;
            this -> rear = -1;
        }

        void push(int val) {
            //overflow, first element, circular nature, normal flow
            if((front == 0 && rear == n-1) || front - rear == 1) cout << "Overflow" << endl;
            else if(front == -1 && rear == -1) {
                front++;
                rear++;
                arr[rear] = val;
            }
            else if(rear == n-1 && front != 0) {
                rear = 0;
                arr[rear] = val;
            }
            else arr[++rear] = val;
        }

        void pop() {
            //underflow, one element, circular nature, nowmal flow
            if(front == -1 && rear == -1) cout << "Underflow" << endl;
            else if(front == rear) {
                arr[front] = 0;
                front = -1;
                rear = -1;
            }
            else if(front == n-1) {
                arr[front] = 0;
                front = 0;
            }
            else arr[front++] = 0;
        }

        int getFront() {
            if(front == -1 && rear == -1) return -1;
            else return arr[front];
        }

        int back() {
            if(front == -1 && rear == -1) return -1;
            else return arr[rear];
        }

        int size() {
            if(front == -1 && rear == -1) return 0;
            else if(rear > front) return rear - front + 1;
            else return n - rear + front + 1;
        }

        bool empty() {
            if(front == -1 && rear == -1) return 1;
            else return 0;
        }

        void print() {
            if(rear < front) {
                for(int i = 0; i <= rear; i++) cout << arr[i] << " ";
                for(int i = front; i < n; i++) cout << arr[i] << " ";
                cout << endl;
            }
            else {
                for(int i = front; i <= rear; i++) cout << arr[i] << " ";
                cout << endl;
            }
        }
};

int main() {
    CircularQueue q(6);

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
    cout << "Empty: " << q.empty() << endl;

    q.pop();
    q.print();
    q.pop();
    q.print();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    q.push(7);
    q.print();
    q.push(8);
    q.print();
    q.push(9);
    q.print();

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    return 0;
}
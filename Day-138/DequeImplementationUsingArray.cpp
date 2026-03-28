#include<iostream>
using namespace std;

class Deque {
    int* arr;
    int n;
    int front;
    int rear;

    public:
        Deque(int size) {
            arr = new int(size);
            this -> n = size;
            this -> front = -1;
            this -> rear = -1;
        }

        void push_back(int val) {
            if(rear == n-1) cout << "Overflow" << endl;
            else if(front == -1 && rear == -1) {
                front++;
                rear++;
                arr[rear] = val;
            }
            else arr[++rear] = val;
        }

        void push_front(int val) {
            if(front == 0) cout << "Overflow" << endl;
            else if(front == -1 && rear == -1) {
                front++;
                rear++;
                arr[front] = val;
            }
            else arr[--front] = val;
        }

        void pop_back() {
            if(front == -1 && rear == -1) cout << "Underflow" << endl;
            else if(front == rear) {
                arr[rear] = 0;
                rear = -1;
                front = -1;
            }
            else arr[rear--] = 0;
        }

        void pop_front() {
            if(front == -1 && rear == -1) cout << "Underflow" << endl;
            else if(front == rear) {
                arr[front] = 0;
                front = -1;
                rear = -1;
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
    Deque dq(6);

    dq.push_front(1);
    dq.print();
    dq.push_back(2);
    dq.print();
    dq.push_back(3);
    dq.print();
    dq.push_back(4);
    dq.print();
    dq.push_back(5);
    dq.print();
    dq.push_back(6);
    dq.print();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;
    cout << "Is Empty: " << dq.isEmpty() << endl;

    dq.pop_front();
    dq.pop_back();
    dq.print();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;
    cout << "Is Empty: " << dq.isEmpty() << endl;

    return 0;
}
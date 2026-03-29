#include<iostream>
using namespace std;

class CircularDeque {
    int* arr;
    int n;
    int front;
    int rear;

    public:
        CircularDeque(int size) {
            arr = new int(size);
            this -> n = size;
            this -> front = -1;
            this -> rear = -1;
        }

        void push_back(int val) {
            //overflow, first element, circular nature, normal flow
            if((front == 0 && rear == n-1) || (front - rear == 1)) cout << "Overflow" << endl;
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

        void push_front(int val) {
            //overflow, first element, circular nature, normal flow
            if((front == 0 && rear == n-1) || (front - rear == 1)) cout << "Overflow" << endl;
            else if(front == -1 && rear == -1) {
                front++;
                rear++;
                arr[front] = val;
            }
            else if(front == 0 && rear != n-1) {
                front = n-1;
                arr[front] = val;
            }
            else arr[--front] = val;
        }

        void pop_back() {
            //underflow, single element, circular nature, normal flow
            if(front == -1 && rear == -1) cout << "Underflow" << endl;
            else if(front == rear) {
                arr[rear] = 0;
                front = -1;
                rear = -1;
            }
            else if(rear == 0) {
                arr[rear] = 0;
                rear = n-1;
            }
            else arr[rear--] = 0;
        }

        void pop_front() {
            //underflow, single element, circular nature, nowmal flow
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
            else return n - front + rear + 1;
        }

        bool empty() {
            if(front == -1 && rear == -1) return 1;
            else return 0;
        }

        void print() {
            if(front <= rear) {
                for(int i = front; i <= rear; i++) cout << arr[i] << " ";
                cout << endl;
            }
            else {
                for(int i = 0; i <= rear; i++) cout << arr[i] << " ";
                for(int i = front; i < n; i++) cout << arr[i] << " ";
                cout << endl;
            }
        }
};

int main() {
    CircularDeque dq(6);

    dq.push_back(1);
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
    dq.push_back(7);

    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;
    cout << "Empty: " << dq.empty() << endl;

    dq.pop_back();
    dq.pop_front();
    dq.print();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;
    cout << "Empty: " << dq.empty() << endl;

    dq.push_back(6);
    dq.push_back(7);
    dq.push_back(8);
    dq.print();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;
    cout << "Empty: " << dq.empty() << endl;

    dq.pop_back();
    dq.pop_front();
    dq.print();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;
    cout << "Empty: " << dq.empty() << endl;

    dq.push_front(2);
    dq.push_front(1);
    dq.push_front(10);
    dq.print();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;
    cout << "Empty: " << dq.empty() << endl;

    return 0;
}
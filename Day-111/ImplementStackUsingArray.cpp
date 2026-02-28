#include<iostream>
using namespace std;

class Stack {
    public:
        int* arr;
        int Size;
        int Top;

        Stack(int capacity) {
            arr = new int(capacity);
            Size = capacity;
            Top = -1;
        }

        void push(int val) {
            if(Top == Size - 1) cout << "Stack overflow" << endl;
            else {
                Top++;
                arr[Top] = val;
            }
        }

        void pop() {
            if(Top == -1) cout << "Stack Underflow" << endl;
            else {
                arr[Top] = 0;
                Top--;
            }
        }

        void top() {
            if(Top == -1) cout << "Stack empty" << endl;
            else cout << "Top Element: " << arr[Top] << endl;
        }

        int size() {
            return Top + 1;
        }

        bool isEmpty() {
            if(Top == -1) return true;
            else return false;
        }

        void print() {
            for(int i = 0; i <= Top; i++) cout << arr[i] << " ";
            cout << endl;
        }
};

int main() {   
    Stack s(6);

    cout << "Size: " << s.size() << endl;
    s.top();
    cout << "Empty: " << s.isEmpty() << endl << endl;

    s.push(1);
    cout << "Elements: ";
    s.print();
    cout << endl;

    cout << "Size: " << s.size() << endl;
    s.top();
    cout << "Empty: " << s.isEmpty() << endl << endl;

    s.push(2);
    cout << "Elements: ";
    s.print();
    cout << endl;

    cout << "Size: " << s.size() << endl;
    s.top();
    cout << "Empty: " << s.isEmpty() << endl << endl;

    s.push(3);
    cout << "Elements: ";
    s.print();
    cout << endl;

    cout << "Size: " << s.size() << endl;
    s.top();
    cout << "Empty: " << s.isEmpty() << endl << endl;

    s.push(4);
    cout << "Elements: ";
    s.print();
    cout << endl;

    cout << "Size: " << s.size() << endl;
    s.top();
    cout << "Empty: " << s.isEmpty() << endl << endl;

    s.push(5);
    cout << "Elements: ";
    s.print();
    cout << endl;

    cout << "Size: " << s.size() << endl;
    s.top();
    cout << "Empty: " << s.isEmpty() << endl << endl;

    s.push(6);
    cout << "Elements: ";
    s.print();
    cout << endl;

    cout << "Size: " << s.size() << endl;
    s.top();
    cout << "Empty: " << s.isEmpty() << endl << endl;

    s.push(7);
    cout << "Elements: ";
    s.print();
    cout << endl;

    cout << "Size: " << s.size() << endl;
    s.top();
    cout << "Empty: " << s.isEmpty() << endl << endl;

    return 0;
}
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void print(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    } cout << endl;
}

void reverseUsingStack(queue<int>& q) {
    stack<int> s;

    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

void reverseUsingRecursion(queue<int>& q) {
    if(q.empty()) return;

    int element = q.front();
    q.pop();

    reverseUsingRecursion(q);

    q.push(element);
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout << "Printing queue before reversing: ";
    print(q);

    // reverseUsingStack(q);
    reverseUsingRecursion(q);

    cout << "Printing queue after reversing: ";
    print(q);

    return 0;
}
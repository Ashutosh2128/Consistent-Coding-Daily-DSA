#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    } cout << endl << endl;
}

void insertAtButtom(stack<int>& s, int element) {
    if(s.empty()) {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtButtom(s, element);

    s.push(top);
}

void reverseStack(stack<int>& s) {
    if(s.empty()) return;

    int top = s.top();
    s.pop();

    reverseStack(s);

    insertAtButtom(s, top);
}

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << "Printing stack before reverse: ";
    printStack(s);

    reverseStack(s);

    cout << "Printing stack after reverse: ";
    printStack(s);

    return 0;
}
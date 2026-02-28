#include<iostream>
#include<stack>
using namespace std;

void insertAtButtom(stack<int>&s, int num) {
    if(s.empty()) {
        s.push(num);
        return;
    }

    int topVal = s.top();
    s.pop();

    insertAtButtom(s, num);

    s.push(topVal);
}

int main() {
    stack<int> s;

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    insertAtButtom(s, 1);

    while(s.top()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
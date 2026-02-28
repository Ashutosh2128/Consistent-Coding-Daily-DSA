#include<iostream>
#include<stack>
using namespace std;

int findMiddle(stack<int> s, int count) {
    if(!count) return s.top();

    s.pop();
    count--;

    return findMiddle(s, count);
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    cout << "Middle Element in stack: " << findMiddle(s, s.size()/2) << endl;

    return 0;
}
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

void reverseInKGroup(queue<int>& q, int k, int currEleSize) {
    if(currEleSize >= k) {
        stack<int> s;
        int count = k;

        while(count--) {
            s.push(q.front());
            q.pop();
        }

        while(!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        reverseInKGroup(q, k, currEleSize - k);
    }
    else {
        while(currEleSize--) {
            q.push(q.front());
            q.pop();
        }
    }
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.push(12);

    int k;
    cout << "Enter the value of k based on what you want to reverse: ";
    cin >> k;

    cout << "Printing queue before reversing: ";
    print(q);

    reverseInKGroup(q, k, q.size());

    cout << "Printing queue after reversing: ";
    print(q);

    return 0;
}
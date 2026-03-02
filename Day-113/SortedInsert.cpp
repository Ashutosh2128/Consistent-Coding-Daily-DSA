#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    } cout << endl << endl;
}

void insertInSorted(stack<int>& s, int num) {
    if(s.empty()) {
        s.push(num);
        return;
    }

    if(s.top() > num) {
        int topE = s.top();
        s.pop();

        insertInSorted(s, num);

        s.push(topE);
    }
    else s.push(num);
}

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int num;
    cout << "Enter the number you want to insert in the stack: ";
    cin >> num;
    cout << endl;

    cout << "Printing stack before inserting element: ";
    print(s);

    insertInSorted(s, num);

    cout << "Printing stack after inserting element: ";
    print(s);

    return 0;
}
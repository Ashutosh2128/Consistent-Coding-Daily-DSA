#include<iostream>
#include<stack>
using namespace std;

bool checkSorted(stack<int>& s, int element1) {
    if(s.empty()) return true;

    int element2 = s.top();
    s.pop();

    if(element1 >= element2) {
        bool ans = checkSorted(s, element2);
        //backtrack
        s.push(element2);
        return ans;
    } else return false;
}

int main() {
    stack<int> s;

    s.push(100);
    s.push(17);
    s.push(35);
    s.push(58);
    s.push(63);

    int element1 = 1000;
    bool sorted = checkSorted(s, element1);

    if(sorted) cout << "Stack is sorted" << endl;
    else cout << "Stack is not sorted" << endl;

    return 0;
}
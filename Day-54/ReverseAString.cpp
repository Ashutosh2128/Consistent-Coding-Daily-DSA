#include<iostream>
using namespace std;

void reverse(string& s, int i, int j) {
    if(i > j) return;

    swap(s[i], s[j]);

    reverse(s, i+1, j-1);
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Reverse of string " << s << " is: ";
    reverse(s, 0, s.length()-1);
    cout << s << endl;

    return 0;
}
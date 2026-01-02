#include<iostream>
using namespace std;

void searchOcc(string s, char ch, int i, int& ans) {
    if(i == s.length()) return;

    if(s[i] == ch) ans = i;

    searchOcc(s, ch, i+1, ans);
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    char ch;
    cout << "Enter the charactor you want to find the last occurance from " << s << ": ";
    cin >> ch;

    int ans = -1; // let say the word is not present

    searchOcc(s, ch, 0, ans);

    if(ans == -1) cout << "Character " << ch << " is not present in the string " << s << endl;
    else cout << "Last Occurance of the charactor " << ch << " in string " << s << " is: " << ans << endl;

    return 0;
}
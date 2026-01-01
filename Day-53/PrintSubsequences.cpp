#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(string input, int i, string output, vector<string>& ans) {
    //base case
    if(i == input.length()) {
        ans.push_back(output);
        return;
    }

    //include
    printSubsequences(input, i+1, output + input[i], ans);
    //exclude
    printSubsequences(input, i+1, output, ans);
}

int main() {
    string input;
    cout << "Enter String: ";
    cin >> input;

    vector<string> ans;

    printSubsequences(input, 0, "", ans);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
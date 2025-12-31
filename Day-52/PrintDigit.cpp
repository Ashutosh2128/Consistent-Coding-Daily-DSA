#include<iostream>
using namespace std;

void printDigit(int n) {
    //base case
    if(n == 0) return;

    //processing
    int digit = n % 10;

    //recursion call
    printDigit(n/10);

    cout << digit << " ";

}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    printDigit(n);

    return 0;
}
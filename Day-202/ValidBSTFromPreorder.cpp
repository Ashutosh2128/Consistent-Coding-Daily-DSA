void checkBST(vector<int>& arr, int& i, int& isBST, int maxi, int mini) {
    if(i == arr.size()) isBST = true;
    
    if(arr[i] > mini && arr[i] < maxi) {
        int val = arr[i++];
        checkBST(arr, i, isBST, val, mini);
        checkBST(arr, i, isBST, maxi, val);
    }
}

int Solution::solve(vector<int> &A) {
    int isBST = false;
    int i = 0;
    int maxi = INT_MAX;
    int mini = INT_MIN;
    
    checkBST(A, i, isBST, maxi, mini);
    
    return isBST;
}
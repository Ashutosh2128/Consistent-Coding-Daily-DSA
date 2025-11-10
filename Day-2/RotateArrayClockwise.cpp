class Solution {
  public:
    void rotateclockwise(vector<int>& arr, int k) {
        int n = arr.size();
        int finalShift = k % n; //incase of k > size of array
        
        vector<int> temp(n); //Creating an temp array to store rotating element
        
        int idx = 0;
        for(int i = n - finalShift; i < n; i++) {
            temp[idx] = arr[i];
            idx++;
        }
        
        for(int i = 0; i < n - finalShift; i++) {
            temp[idx] = arr[i];
            idx++;
        }
        
        //Now copy from temp arrat to main array
        for(int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};

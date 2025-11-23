class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 1; i < n; i++) {
            int ele = arr[i];
            int j = i - 1;
            
            while(j >= 0) {
                if(arr[j] > ele) {
                    arr[j+1] = arr[j];
                    j--;
                }
                else break;
            }
            
            arr[j+1] = ele;
        }
    }
};
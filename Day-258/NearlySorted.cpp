class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int idx = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            minHeap.push(arr[i]);
            
            if(minHeap.size() > k) {
                arr[idx++] = minHeap.top();
                minHeap.pop();
            }
        }
        
        while(!minHeap.empty()) {
            arr[idx++] = minHeap.top();
            minHeap.pop();
        }
    }
};




// class Solution {
//   public:
//     void nearlySorted(vector<int>& arr, int k) {
//         priority_queue<int, vector<int>, greater<int>> minHeap;
        
//         for(const int& i : arr) minHeap.push(i);
        
//         for(int i = 0; i < arr.size(); i++) {
//             arr[i] = minHeap.top();
//             minHeap.pop();
//         }
//     }
// };
class Solution {
  public:
    int minComputation(vector<int> &files) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int file : files) minHeap.push(file);
        
        int total = 0;
        
        while(minHeap.size() > 1) {
            int first = minHeap.top();
            minHeap.pop();
            
            int second = minHeap.top();
            minHeap.pop();
            
            total += first + second;
            minHeap.push(first + second);
        }
        
        return total;
    }
};
class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int n = arr.size();
        int steps = 0;
        
        while(1) {
            // by this we make all element even
            for(int i = 0; i < n; i++) {
                if(arr[i] % 2 != 0) {
                    arr[i]--;
                    steps++;
                }
            }
            
            // Now check wheather all elements get zero or not
            bool allZero = true;
            for(const int& it : arr) {
                if(it != 0) {
                    allZero = false;
                    break;
                }
            }
            
            if(allZero) break;
            
            // in this step we have all even element, now divide all even element with 2
            for(int i = 0; i < n; i++) arr[i] = arr[i]/2;
            steps++; // after all the even number division inscrease steps by one only
        } 
        
        return steps;
    }
};
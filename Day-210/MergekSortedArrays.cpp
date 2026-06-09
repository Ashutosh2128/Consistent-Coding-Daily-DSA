class Solution {
  public:
    class Info {
        public:
            int data;
            int rIndex;
            int cIndex;
            
            Info(int d, int ri, int ci) {
                this -> data = d;
                this -> rIndex = ri;
                this -> cIndex = ci;
            }
    };
    
    class compare {
        public:
            bool operator()(Info* a, Info* b) {
                return a -> data > b -> data;
            }
    };
  
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;
        
        int rowLength = mat.size();
        int colLength = mat[0].size();
        
        for(int i = 0; i < rowLength; i++) {
            Info* temp = new Info(mat[i][0], i, 0);
            pq.push(temp);
        }
        
        while(!pq.empty()) {
            Info* front = pq.top();
            pq.pop();
            
            int val = front -> data;
            int rowIndex = front -> rIndex;
            int colIndex = front -> cIndex;
            
            ans.push_back(val);
            
            if(colIndex + 1 < colLength) {
                Info* temp = new Info(mat[rowIndex][colIndex+1], rowIndex, colIndex+1);
                pq.push(temp);
            }
        }
        
        return ans;
    }
};
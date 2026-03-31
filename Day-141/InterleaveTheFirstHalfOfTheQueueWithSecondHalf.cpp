class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> q2;
        int halfSize = q.size() / 2;
        
        while(halfSize--) {
            q2.push(q.front());
            q.pop();
        }
        
        while(!q2.empty()) {
            q.push(q2.front());
            q.push(q.front());
            q2.pop();
            q.pop();
        }
    }
};
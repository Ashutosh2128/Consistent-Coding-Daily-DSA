class Solution {
  public:
    vector<int> topView(Node *root) {
        queue<pair<int, Node*>> q;
        unordered_map<int, Node*> mp;
        
        q.push(make_pair(0, root));
        int minDis = INT_MAX;
        int maxDis = INT_MIN;
        
        while(!q.empty()) {
            pair<int, Node*> front = q.front();
            q.pop();
            
            int dis = front.first;
            Node* node = front.second;
            minDis = min(minDis, dis);
            maxDis = max(maxDis, dis);
            
            if(mp.find(dis) == mp.end()) mp[dis] = node;
            
            if(node -> left) q.push(make_pair(dis-1, node -> left));
            if(node -> right) q.push(make_pair(dis+1, node -> right));
        }
        
        vector<int> ans;
        for(int i = minDis; i <= maxDis; i++) {
            ans.push_back(mp[i] -> data);
        }
        
        return ans;
    }
};
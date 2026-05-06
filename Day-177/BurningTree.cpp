class Solution {
  public:
    Node* findTargetNodeAndNodeToParentMapping(Node* root, int target, unordered_map<Node*, Node*>& parentMap) {
        Node* targetNode = nullptr;
        parentMap[root] = nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if(front -> data == target) targetNode = front;
            
            if(front -> left) {
                q.push(front -> left);
                parentMap[front -> left] = front;
            }
            
            if(front -> right) {
                q.push(front -> right);
                parentMap[front -> right] = front;
            }
        }
        
        return targetNode;
    }
    
    int totalTimeRequired(Node* targetNode, unordered_map<Node*, Node*>& parentMap) {
        unordered_map<Node*, bool> vis;
        int totalTime = 0;
        
        queue<Node*> q;
        q.push(targetNode);
        vis[targetNode] = true;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();
                
                if(front -> left && vis.find(front -> left) == vis.end()) {
                    q.push(front -> left);
                    vis[front -> left] = true;
                }
                
                if(front -> right && vis.find(front -> right) == vis.end()) {
                    q.push(front -> right);
                    vis[front -> right] = true;
                }
                
                if(parentMap[front] && vis.find(parentMap[front]) == vis.end()) {
                    q.push(parentMap[front]);
                    vis[parentMap[front]] = true;
                }
            }
            
            totalTime++;
        }
        
        return totalTime - 1;
    }
  
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = findTargetNodeAndNodeToParentMapping(root, target, parentMap);
        
        return totalTimeRequired(targetNode, parentMap);
    }
};
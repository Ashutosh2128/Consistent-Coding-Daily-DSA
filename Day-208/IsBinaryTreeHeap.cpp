class Solution {
  public:
    bool checkCompleteNess(Node* root) {
        if(!root) return true;
        
        queue<Node*> q;
        q.push(root);
        bool isRight = true;
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            bool isLeft = true;
            
            if(front -> left) {
                q.push(front -> left);
                if(!isRight) return false;
            }
            else isLeft = false;
            
            if(front -> right) {
                q.push(front -> right);
                if(!isLeft) return false;
            }
            else isRight = false;
        }
        
        return true;
    }
    
    bool checkMaxProperty(Node* root) {
        if(!root) return true;
        if(!root -> left && !root -> right) return true;
        
        bool leftAns = checkMaxProperty(root -> left);
        bool rightAns = checkMaxProperty(root -> right);
        
        // bool opt1 = true;
        // if(root -> left && (root -> data < root -> left -> data)) opt1 = false;
        
        // bool opt2 = true;
        // if(root -> right && (root -> data < root -> right -> data)) opt2 = false;
        
        // bool currAns = opt1 && opt2;
        
        bool currAns = (root -> left && (root -> data > root -> left -> data)) ? true : false && 
                       (root -> right && (root -> data > root -> right -> data)) ? true : false;
                       
        return leftAns && rightAns && currAns;
    }
  
    bool isHeap(Node* tree) {
        return checkCompleteNess(tree) && checkMaxProperty(tree);
    }
};
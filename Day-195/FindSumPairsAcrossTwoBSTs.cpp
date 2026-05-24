class Solution {
  public:
    int countPairs(Node* root1, Node* root2, int x) {
        stack<Node*> s1, s2;
        Node* a = root1; 
        Node* b = root2;
        int ans = 0;
        
        while(1) {
            while(a) {
                s1.push(a);
                a = a -> left;
            }
            
            while(b) {
                s2.push(b);
                b = b -> right;
            }
            
            if(s1.empty() || s2.empty()) break;
            
            Node* top1 = s1.top();
            Node* top2 = s2.top();
            int sum = top1 -> data + top2 -> data;
            
            if(sum == x) {
                ans++;
                s1.pop();
                s2.pop();
                a = top1 -> right;
                b = top2 -> left;
            }
            else if(sum < x) {
                s1.pop();
                a = top1 -> right;
            }
            else {
                s2.pop();
                b = top2 -> left;
            }
        }
        
        return ans;
    }
};








// Require O(n) and O(n) TC and SC
// class Solution {
//   public: 
//     void storeInorder(Node* root, vector<int>& inorder) {
//         if(!root) return;
        
//         storeInorder(root -> left, inorder);
//         inorder.push_back(root -> data);
//         storeInorder(root -> right, inorder);
//     }
    
//     int countPairs(Node* root1, Node* root2, int x) {
//         vector<int> in1;
//         vector<int> in2;
        
//         storeInorder(root1, in1);
//         storeInorder(root2, in2);
        
//         int n1 = in1.size();
//         int n2 = in2.size();
//         int ans = 0;
        
//         int i = 0;
//         int j = n2-1;
//         while(i < n1 && j >= 0) {
//             int sum = in1[i] + in2[j];
            
//             if(sum == x) {
//                 ans++;
//                 i++;
//                 j--;
//             }
//             else if(sum < x) i++;
//             else j--;
//         }
        
//         return ans;
//     }
// };







// Got TLE for last 2 test cases
// class Solution {
//   public:
//     bool isPresent(Node* root, int req) {
//         if(!root) return false;
//         if(root -> data == req) return true;
        
//         bool left = false;
//         bool right = false;
        
//         if(req < root -> data) left = isPresent(root -> left, req);
//         else right = isPresent(root -> right, req);
        
//         return left || right;
//     }
  
//     void solve(Node* root1, Node* root2, int x, int& ans) {
//         if(!root1) return;
        
//         int require = x - root1 -> data;
//         if(isPresent(root2, require)) ans++;
        
//         solve(root1 -> left, root2, x, ans);
//         solve(root1 -> right, root2, x, ans);
//     }
  
//     int countPairs(Node* root1, Node* root2, int x) {
//         int ans = 0;
//         solve(root1, root2, x, ans);
        
//         return ans;
//     }
// };
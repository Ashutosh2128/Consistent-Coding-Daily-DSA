class Solution {
public:
    TreeNode* buildBST(vector<int>& preorder, int& i, int min, int max) {
        if(i >= preorder.size()) return nullptr;

        TreeNode* root = nullptr;
        if(preorder[i] > min && preorder[i] < max) {
            root = new TreeNode(preorder[i++]);
            root -> left = buildBST(preorder, i, min, root -> val);
            root -> right = buildBST(preorder, i, root -> val, max);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        int min = INT_MIN, max = INT_MAX;
        TreeNode* root = buildBST(preorder, idx, min, max);

        return root;
    }
};








// class Solution {
// public:
//     int findIdx(vector<int>& inorder, int st, int end, int key) {
//         if(st > end) return -1;

//         int mid = st + (end - st) / 2;
//         if(inorder[mid] == key) return mid;
//         else if(inorder[mid] < key) return findIdx(inorder, mid+1, end, key);
//         else return findIdx(inorder, st, mid-1, key);
//     }

//     TreeNode* buildBST(vector<int>& preorder, vector<int>& inorder, int& idx, int inStartIdx, int inEndIdx, int n) {
//         if(idx >= n) return nullptr;
//         if(inStartIdx > inEndIdx) return nullptr;

//         int element = preorder[idx++];
//         TreeNode* root = new TreeNode(element);

//         int inIdx = findIdx(inorder, inStartIdx, inEndIdx, element);

//         root -> left = buildBST(preorder, inorder, idx, inStartIdx, inIdx - 1, n);
//         root -> right = buildBST(preorder, inorder, idx, inIdx + 1, inEndIdx, n);

//         return root;
//     }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int n = preorder.size();

//         vector<int> inorder(n);
//         inorder = preorder;
//         sort(inorder.begin(), inorder.end());

//         int idx = 0;
//         TreeNode* root = buildBST(preorder, inorder, idx, 0, n-1, n);

//         return root;
//     }
// };










// class Solution {
// public:
//     TreeNode* buildBST(TreeNode* root, int element) {
//         if(!root) {
//             TreeNode* node = new TreeNode(element);
//             return node;
//         }

//         if(element < root -> val) root -> left = buildBST(root -> left, element);
//         else root -> right = buildBST(root -> right, element);

//         return root;
//     }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode* root = nullptr;
//         for(int i = 0; i < preorder.size(); i++) root = buildBST(root, preorder[i]);

//         return root;
//     }
// };
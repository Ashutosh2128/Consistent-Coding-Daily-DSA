class Codec {
public:
    vector<string> encode;

    void preorder(TreeNode* root) {
        if(!root) {
            encode.push_back("#");
            return;
        }

        encode.push_back(to_string(root -> val));

        preorder(root -> left);
        preorder(root -> right);
    }

    string serialize(TreeNode* root) {
        encode.clear(); // without this line it create Restriction Failed error

        preorder(root);

        string serial = "";
        for(string it : encode) serial += it + ",";

        return serial;
    }

    TreeNode* solve(vector<string>& values, int& idx) {
        if(idx >= values.size()) return nullptr;
        if(values[idx] == "#") {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(values[idx]));
        idx++;

        root -> left = solve(values, idx);
        root -> right = solve(values, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> values;

        stringstream s(data);
        string temp;

        while(getline(s, temp, ',')) values.push_back(temp);

        int idx = 0;
        return solve(values, idx);
    }
};









// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Codec {
// public:
//     void preorder(TreeNode* root, string& serial) {
//         if(!root) {
//             serial += '#';
//             return;
//         }

//         serial += char(root -> val);

//         preorder(root -> left, serial);
//         preorder(root -> right, serial);
//     }

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string serial = "";
//         preorder(root, serial);

//         return serial;
//     }

//     TreeNode* deserial(string& data, int& idx) {
//         if(data[idx] == '#') {
//             idx++;
//             return nullptr;
//         }

//         TreeNode* root = new TreeNode(data[idx] - '0');
//         idx++;

//         root -> left = deserial(data, idx);
//         root -> right = deserial(data, idx);

//         return root;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         int idx = 0;
//         return deserial(data, idx);
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));
Node* findPredecessor(Node* root, Node* p) {
    Node* pred = nullptr;
	Node* curr = root;
	
	while(curr) {
		if(curr -> data < p -> data) {
			pred = curr;
			curr = curr -> right;
		}
		else curr = curr -> left;
	}
	
	return pred;
}





// void storeInorder(Node* root, vector<Node*>& inorder) {
// 	if(!root) return;
	
// 	storeInorder(root -> left, inorder);
// 	inorder.push_back(root);
// 	storeInorder(root -> right, inorder);
// }

// int searchNode(vector<Node*>& inorder, Node* p) {
// 	int s = 0;
// 	int e = inorder.size()-1;
	
// 	while(s <= e) {
// 		int mid = s + (e-s) / 2;
		
// 		if(inorder[mid] -> data == p -> data) return mid;
// 		else if(inorder[mid] -> data < p -> data) s = mid + 1;
// 		else e = mid - 1;
// 	}
	
// 	//Not found
// 	return -1;
// }

// Node* findPredecessor(Node* root, Node* p) {
//     vector<Node*> inorder;
// 	storeInorder(root, inorder);
	
// 	int idx = searchNode(inorder, p);
	
// 	return idx > 0 ? inorder[idx-1] : nullptr;
	
// 	return 
// }
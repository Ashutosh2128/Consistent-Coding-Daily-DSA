class Solution {
public:
    int solve(TreeNode* root, int& cameras) {
        if(!root) return 1;

        int left = solve(root -> left, cameras);
        int right = solve(root -> right, cameras);

        if(left == 0 || right == 0) {
            //if any of these have not covered then need to install camera
            //conditions -> (left = 2, right = 0), (left = 0, right = 2), 
                            // (left = 1, right = 0), (left = 0, right = 1)
                            // (left = 0, right = 0)
            cameras++;
            return 2;
        }
        if(left == 2 || right == 2) 
            //if any of has 2 no need to install it already covered
            //conditions -> (left = 2, right = 1), (left = 1, right = 2), (left = 2, right = 2)
            return 1;

        //otherwise return 0
        return 0; //conditions - (left = 1, right = 1)
    }

    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if(!root) return cameras;

        int states = solve(root, cameras);
        if(states == 0) cameras++;

        return cameras;
    }
};
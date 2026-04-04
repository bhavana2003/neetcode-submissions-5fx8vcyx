/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int rightMin = 1001, leftMax = -1001;
        return isValidUntil(root, rightMin, leftMax);
    }

    bool isValidUntil(TreeNode* root, int rightMin, int leftMax){
        if (root == NULL)   return true;

        if (root->val >= rightMin || root->val <= leftMax)
            return false;

        return isValidUntil(root->left, root->val, leftMax) && isValidUntil(root->right, rightMin, root->val);
    }
};

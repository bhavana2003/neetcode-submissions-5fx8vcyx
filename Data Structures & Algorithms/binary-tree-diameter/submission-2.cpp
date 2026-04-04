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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)   return 0;
        int maxi = 0;
        maxDepth(root, maxi);
        return maxi;
    }

    // Node maintains depth
    // diameter maintains max D
    // postorder

    int maxDepth(TreeNode* root, int &diameter) {
        if (root == NULL)   return 0;
        int left = maxDepth(root->left, diameter);
        int right = maxDepth(root->right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
};

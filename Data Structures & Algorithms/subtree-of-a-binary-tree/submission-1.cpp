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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string r = serialize(root);
        string s = serialize(subRoot);
        return r.find(s) != string::npos;
    }

    string serialize(TreeNode* root) {
        if (!root) return "#,";   // NULL marker

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }
};
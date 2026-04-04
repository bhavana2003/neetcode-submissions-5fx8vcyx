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
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL)   return -1;
        int count = 0;
        stack <TreeNode*> st;
        st.push(root);
        while(!st.empty() || root){
            while(root && root->left){
                st.push(root->left);
                root = root->left;
            }

            root = st.top();
            st.pop();

            // cout << root->val << count << endl;
            count++;
            if (count == k){
                return root->val;
            }
            
            if (root->right)    st.push(root->right);
            root = root->right;
        }
        return -1;
    }
};

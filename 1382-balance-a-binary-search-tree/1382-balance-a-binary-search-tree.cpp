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
private:
    void inorder(TreeNode* root, vector<int> &in)
    {
        if(root == NULL)
            return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* balBST(int s, int e, vector<int> in)
    {
        if(s>e)
            return NULL;
        int m = (e-s)/2 + s;
        TreeNode* root = new TreeNode(in[m]);
        root->left = balBST(s,m-1,in);
        root->right = balBST(m+1,e,in);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        return balBST(0,in.size()-1,in);
    }
};
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
    int small(TreeNode* root, int &i, int k)
    {
        if(root == NULL)
            return -1;
        int left = small(root->left,i,k);
        if(left != -1)
            return left;
        i++;
        if(i == k)
            return root->val;
        return small(root->right,i,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return small(root,i,k);
    }
};
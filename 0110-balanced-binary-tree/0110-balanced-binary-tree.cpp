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
    int dfsSearch(TreeNode* root)
    {
        if(root == NULL)
        {
            //returning the height at last level
            return 0;
        }
        int left = dfsSearch(root->left);
        int right = dfsSearch(root->right);
        if(left == -1 || right == -1 || abs(left-right)>1)
            return -1;
        return max(left,right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfsSearch(root) != -1;
    }
};
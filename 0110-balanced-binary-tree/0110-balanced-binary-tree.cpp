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
    pair<bool,int> balanceFast(TreeNode* root)
    {
        if(root == NULL)
        {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = balanceFast(root->left);
        pair<bool,int> right = balanceFast(root->right);        
        pair<bool,int> ans;
        if(left.first && right.first && abs(left.second - right.second) <= 1) //check for balance
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        ans.second = max(left.second,right.second)+1;  //height
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return balanceFast(root).first;
    }
};
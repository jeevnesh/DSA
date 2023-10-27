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
#include<queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> ans;
        vector<vector<int>> outputAns;
        queue<TreeNode *> q;
        if(root == NULL)
        {
            return outputAns;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* temp;
            temp = q.front();
            q.pop();
            if(temp == NULL)
            {
               if(!q.empty())
               {
                   q.push(NULL);   
               }
               outputAns.push_back(ans);
               ans.clear();
            }
            else
            {
                ans.push_back(temp->val);
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return outputAns;
    }
};
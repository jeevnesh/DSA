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
    void reverse(vector<vector<int>> &outputAns)
    {
        int i = 0;
        int j = outputAns.size()-1;
        while(j>=i)
        {
            swap(outputAns[i],outputAns[j]);
            i++;
            j--;
        }
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>> outputAns;
        if(root == NULL)
            return outputAns;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> ans;
            for(int i = 0 ; i < n ; i++)
            {
                TreeNode* temp = q.front();
                ans.push_back(temp->val);
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            outputAns.push_back(ans);
        }
        reverse(outputAns);
        return outputAns;
    }
};
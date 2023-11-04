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
    TreeNode* createMap(TreeNode* root, map<TreeNode*,TreeNode*> &nodeToParent, int start)
    {
        //do level order travesal
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val == start)
                res = temp;
            if(temp->left)
            {
                nodeToParent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                nodeToParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return res;
    }
    int infection(TreeNode* root, map<TreeNode*,TreeNode*> &nodeToParent)
    {
        int time = 0;
        map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;
        while(!q.empty())
        {
            int size = q.size();
            int flag = 0;
            for(int i = 0 ; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left])
                {
                    flag = 1;
                    visited[temp->left] = true;
                    q.push(temp->left);
                }
                if(temp->right && !visited[temp->right])
                {
                    flag = 1;
                    visited[temp->right] = true;
                    q.push(temp->right);
                }
                if(nodeToParent[temp] && !visited[nodeToParent[temp]])
                {
                    flag = 1;
                    visited[nodeToParent[temp]] = true;
                    q.push(nodeToParent[temp]);
                }
            }
            if(flag==1)
                time++;
        }
        return time;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        //create maptonode and return target element
        map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* targetNode = createMap(root,nodeToParent,start);
        int ans = infection(targetNode,nodeToParent);
        return ans;
    }
};
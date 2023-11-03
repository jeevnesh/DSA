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
    void createMap(vector<int> inorder, map<int,int> &nodeToIndex, int size)
    {
        for(int i = 0 ; i < size; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int> inorder, vector<int> postorder, 
                    int &postOrderIndex, int inorderStart, int inorderEnd, int size, map<int,int> &nodeToIndex)
    {
        if(postOrderIndex < 0 || inorderStart > inorderEnd)
            return NULL;
        int element = postorder[postOrderIndex--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        root->right = solve(inorder,postorder,postOrderIndex,position+1,inorderEnd,size,nodeToIndex);
        root->left = solve(inorder,postorder,postOrderIndex,inorderStart,position-1,size,nodeToIndex);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int postOrderIndex = size-1;
        map<int,int> nodeToIndex;
        createMap(inorder,nodeToIndex,size);
        TreeNode* ans = solve(inorder,postorder,postOrderIndex,0,size-1,size,nodeToIndex);
        return ans;
    }
};
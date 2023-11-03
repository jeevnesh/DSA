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
    int findPosition(vector<int> inorder, int element, int size)
    {
        for(int i = 0; i<size; i++)
        {
            if(inorder[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int> inorder, vector<int> preorder, int &preOrderIndex, int inOrderStart, int inOrderEnd, int size)
    {
        // base case
        if(preOrderIndex >= size || inOrderStart > inOrderEnd)
            return NULL;
        //create root element
        int element = preorder[preOrderIndex++];
        //create node
        TreeNode* root = new TreeNode(element);
        //find the position of this node in InOrder
        int position = findPosition(inorder,element,size);
        //recursive call
        root->left = solve(inorder,preorder,preOrderIndex,inOrderStart,position-1,size);
        root->right = solve(inorder,preorder,preOrderIndex,position+1,inOrderEnd,size);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int size = inorder.size();
        TreeNode* ans = solve(inorder,preorder,preOrderIndex,0,size-1,size);
        return ans;
    }
};
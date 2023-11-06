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
        TreeNode* curr = root;
        int Ksmallest = 0;
        //count variable to keep count of visited nodes
        int count = 0;
        while(curr != NULL)
        {
            //if left is null
            if(curr->left == NULL)
            {
                // first increment count and check if count = k
                if(++count == k)
                    Ksmallest = curr->val;
                // otherwise move to the right child
                curr = curr->right;
            }
            else
            {
                // find inorder predeccessor of current Node
                TreeNode* pred = curr->left;
                while(pred->right != NULL && pred->right != curr)
                    pred = pred->right;
                if(pred->right == NULL)
                {
                    // set right child of predeccessor to the current Node
                    pred->right = curr;
                    // move current to its left
                    curr = curr->left;
                }
                 // restoring the tree back to original binary
                // search tree removing threaded links
                else
                {
                    pred->right = NULL;
                    if(++count == k)
                        Ksmallest = curr->val;
                    curr = curr->right;
                }
            }  
        }
        return Ksmallest;
    }
};
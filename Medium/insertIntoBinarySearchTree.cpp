/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void actualInsertion(int val, TreeNode* currentNode){
        if(val < currentNode->val){
            if(currentNode->left)
                actualInsertion(val, currentNode->left);
            else
                currentNode->left = new TreeNode(val);
        } else { 
            if(currentNode->right)
                actualInsertion(val, currentNode->right);
            else 
                currentNode->right = new TreeNode(val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            root = new TreeNode(val);
        else
            actualInsertion(val, root);
        return root;
    }
};
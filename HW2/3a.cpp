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
    //Function that validates a BST
    bool isValidBST(TreeNode* root)
    {
        //check if the tree is empty
        if (root == NULL)
        {
            return true;
        }
        return dfs(root, NULL, NULL);
    }

    //DFS funciton that return true if all nodes of left subtree are less then the 
    //root and all of the nodes on the right subtree are greater than the root 
    bool dfs(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        //Check if the node is NULL
        if (root == NULL)
        {
            return true;
        }
        //check if the node value on the left side is less than the root value and node
        //value on the right side of the tree is greater than the root
        if ((min != NULL && root->val <= min->val) || (max != NULL && root->val >= max->val))
        {
            return false;
        }
        //Recursively calls the DFS
        return dfs(root->left, min, root) && dfs(root->right, root, max);
    }
};
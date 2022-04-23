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
    //Incert function
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //Check if the tree is empty
        if (root == NULL)
        {
            TreeNode* node = new TreeNode;
            node->val = val;
            return node;
        }
        //Check if the root value is grater then the new node value
        if (val < root->val)
        {
            //Insert if the left pointer is pointing to null
            if (root->left == NULL)
            {
                TreeNode* node = new TreeNode;
                node->val = val;
                root->left = node;
                return root;
            }
            //Recursively call incert function
            else
            {
                insertIntoBST(root->left, val);
            }
        }
        //If the root value is less then the new node value
        else
        {
            //Insert if the left pointer is pointing to null
            if (root->right == NULL)
            {
                TreeNode* node = new TreeNode;
                node->val = val;
                root->right = node;
                return root;
            }
            //Recursively call incert function
            else
            {
                insertIntoBST(root->right, val);
            }
        }
        return root;
    }
};
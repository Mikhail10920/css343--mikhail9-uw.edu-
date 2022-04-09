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
    void flatten(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }
        //Write node to don't lose them while switch.
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        TreeNode* button = root;
        root->left = NULL;
        // Call function recursively to go to down levels.
        flatten(left);
        flatten(right);
        //Switch right node to left
        root->right = left;
        while (button->right != NULL)
        {
            button = button->right;
        }
        button->right = right;
    }
};
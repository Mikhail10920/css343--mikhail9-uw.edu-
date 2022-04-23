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
    //Delete node
    TreeNode* deleteNode(TreeNode* root, int key) {
        //Get parent of the node that we want to delete
        TreeNode* parant = searchNodeParant(root, root, key);
        //Going to the tree to delete the node with the key value
        deleteNodeInTree(root, parant, key);
        return root;
    }
    //Search the tree for the parent of the node with the key value and return it
    TreeNode* searchNodeParant(TreeNode* root, TreeNode* parant, int val)
    {
        //Check if the node equals null
        if (root == NULL)
        {
            return NULL;
        }
        //Returns parent of the node with the key value 
        if (root->val == val)
        {
            return parant;
        }
        //Recursively call the search function for the left subtree
        if (val < root->val)
        {
            return searchNodeParant(root->left, root, val);
        }
        //Recursively call the search function for the right subtree
        else
        {
            return searchNodeParant(root->right, root, val);
        }
    }

    //Delete node with the key value from the tree
    void deleteNodeInTree(TreeNode*& root, TreeNode*& nodeParant, int key)
    {
        TreeNode* nodeToDelete;
        bool right;
        //Check if the tree is empty
        if (nodeParant == NULL)
        {
            return;
        }
        //Check if a tree has only the root and it contains the key value. And if true,
        //delete it
        if ((root->val == key) && (root->left == NULL) && (root->right == NULL))
        {
            delete root;
            root = NULL;
            return;
        }
        //Looking for a node that needs to be deleted(because we have only 
        //a parent of it)
        //If it is on the left side of the parent 
        if ((nodeParant->left != NULL) && (nodeParant->left->val == key))
        {
            nodeToDelete = nodeParant->left;
            right = false;
        }
        //If it is on the right side of the parent 
        else if ((nodeParant->right != NULL) && (nodeParant->right->val == key))
        {
            nodeToDelete = nodeParant->right;
            right = true;
        }
        //If we need to delete root of the tree that doesn't have a parent
        else
        {
            nodeToDelete = nodeParant;
            if (nodeToDelete->right != NULL)
            {
                right = true;
            }
            else
            {
                right = false;
            }
        }
        //Check for three cases
        //If the node that we need to delete is a leaf
        if ((nodeToDelete->left == NULL) && (nodeToDelete->right == NULL))
        {
            deleatLeaf(nodeToDelete, nodeParant, key, right);
        }
        //If the node that we need to delete has only one child
        else if ((nodeToDelete->left == NULL) || (nodeToDelete->right == NULL))
        {
            deleatNodeWithOneChiled(root, nodeToDelete, nodeParant, key, right);
        }
        //If the node that we need to delete has two children
        else if ((nodeToDelete->left != NULL) && (nodeToDelete->right != NULL))
        {
            deleatNodeWithTwoChiledren(root, nodeToDelete, nodeParant, key, right);
        }
    }

    //Delete a leaf
    void deleatLeaf(TreeNode*& nodeToDelete, TreeNode*& nodeParant, int key, bool right)
    {
        if ((nodeToDelete->left == NULL) && (nodeToDelete->right == NULL))
        {
            if (right)
            {
                delete nodeToDelete;
                nodeParant->right = NULL;

            }
            else
            {
                delete nodeToDelete;
                nodeParant->left = NULL;
            }
        }
    }

    //Delete node with only one child
    void deleatNodeWithOneChiled(TreeNode*& root, TreeNode*& nodeToDelete, TreeNode*& nodeParant, int key, bool right)
    {
        if ((nodeToDelete->left == NULL) || (nodeToDelete->right == NULL))
        {
            TreeNode* nodeChild;
            //Assign  a child of the node we are going to delete
            if (nodeToDelete->left == NULL)
            {
                nodeChild = nodeToDelete->right;
            }
            else
            {
                nodeChild = nodeToDelete->left;
            }
            //Delete the node and assign the parent to it's child
            if (right)
            {
                //If we are deleting the root
                if (nodeParant == nodeToDelete)
                {
                    TreeNode* temp = nodeParant->right;
                    delete nodeToDelete;
                    root = temp;
                }
                //All other cases
                else
                {
                    nodeParant->right = nodeChild;
                    delete nodeToDelete;
                }
            }
            else
            {
                //If we are deleting the root
                if (nodeParant == nodeToDelete)
                {
                    TreeNode* temp = nodeParant->left;
                    delete root;
                    root = temp;
                }
                //All other cases
                else
                {
                    nodeParant->left = nodeChild;
                    delete nodeToDelete;
                }
            }
        }
    }

    //Delete node with two children
    void deleatNodeWithTwoChiledren(TreeNode*& root, TreeNode*& nodeToDelete, TreeNode*& nodeParant, int key, bool right)
    {
        TreeNode* cur = nodeToDelete->right;
        TreeNode* perent = nodeToDelete->right;
        //Going left as far as possible
        while (cur->left != NULL)
        {
            perent = cur;
            cur = cur->left;
        }
        //Replace value in deleted node with the most left
        nodeToDelete->val = cur->val;
        //Assigned perent
        if (perent->left != NULL)
        {
            perent->left = cur->right;
        }
        else
        {
            nodeToDelete->right = perent->right;
        }
        delete cur;
    }
};
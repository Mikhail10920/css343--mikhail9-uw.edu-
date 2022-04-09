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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = inorder.size() - 1;
        //Return a root for a new.
        return build(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }

    //Build a tree and return a root.
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int indStart, int indEnd, int& postIndex)
    {
        if (indStart > indEnd)
        {
            return NULL;
        }
        //Creates a new node.
        TreeNode* newNode = new TreeNode;
        newNode->val = postorder[postIndex];
        postIndex--;
        //Return node if the function went through all of the nodes.
        if (indStart == indEnd)
        {
            return newNode;
        }
        //Search for a node index with the value in a inorder vector. 
        int inorIndex = 0;
        while (newNode->val != inorder[inorIndex])
        {
            inorIndex++;
        }
        //Call function recursively to build right and left sub tree. 
        newNode->right = build(inorder, postorder, inorIndex + 1, indEnd, postIndex);
        newNode->left = build(inorder, postorder, indStart, inorIndex - 1, postIndex);
        return newNode;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
        {
            return NULL;
        }
        //Node that will keep track of the beginning node on each level.
        Node* newLevel = root;
        //Will go through all of the levels.
        while (newLevel != NULL)
        {
            //Node that will go through all of the nodes on the level.
            Node* cur = newLevel;
            //Will go though all of the nodes on the level.
            while (cur != NULL)
            {
                //Make connections with left and right nodes.
                if (cur->left != NULL)
                {
                    cur->left->next = cur->right;
                    //Make connections with the right and next left node.
                    if (cur->next != NULL)
                    {
                        cur->right->next = cur->next->left;
                    }
                }
                //Move to the next node on the level.
                cur = cur->next;
            }
            //Move to the next level.
            newLevel = newLevel->left;
        }
        return root;
    }
};
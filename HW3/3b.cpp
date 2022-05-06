/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    //clone node
    Node* cloneNode(Node* oldNode)
    {
        Node* newNode = new Node;
        newNode->val = oldNode->val;
        return newNode;
    }
    //do dfs for a node and its neighbors
    void dfs(Node* nighb, Node* newNighb, vector<Node*>& visited)
    {
        visited[newNighb->val] = newNighb;
        //going through all of the neighbors
        for (Node* n : nighb->neighbors)
        {
            //if not visited clone node and call dfs
            if (visited[n->val] == NULL)
            {
                Node* newNode = cloneNode(n);
                (newNighb->neighbors).push_back(newNode);
                dfs(n, newNode, visited);
            }
            //if visited, put reference to the clone neighbor to the cloned node 
            else
            {
                (newNighb->neighbors).push_back(visited[n->val]);
            }
        }
    }

    //clone graph
    Node* cloneGraph(Node* node) {
        //vector for visited nodes
        vector<Node*> visited(100000, NULL);
        //base case
        if (node == NULL)
        {
            return NULL;
        }
        //clone the first node
        Node* newNode = cloneNode(node);
        //put first node to visited
        visited[node->val] = newNode;
        //going through  all of the neighbors
        for (Node* nighb : node->neighbors)
        {
            if (visited[nighb->val] == NULL)
            {
                Node* newNighb = cloneNode(nighb);
                (newNode->neighbors).push_back(newNighb);
                dfs(nighb, newNighb, visited);
            }
            else
            {
                (newNode->neighbors).push_back(visited[nighb->val]);
            }
        }
        return newNode;
    }
};
class Node
{
public:
    Node* children[26];
    bool endOfWord = false;
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};


class Trie {
public:
    Node* root = new Node;

    //incert a word
    void insert(string word) {
        Node* cur = root;
        //going thoght each letter 
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (!cur->children[index])
            {
                Node* newNode = new Node;
                cur->children[index] = newNode;
            }
            cur = cur->children[index];
        }
        cur->endOfWord = true;
    }

    //Search for a word 
    bool search(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (cur->children[index] == NULL)
            {
                return false;
            }
            else
            {
                cur = cur->children[index];
            }
        }
        if (cur->endOfWord)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //Check for a start with prifix
    bool startsWith(string prefix) {
        Node* cur = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            int index = prefix[i] - 'a';
            if (cur->children[index] == NULL)
            {
                return false;
            }
            else
            {
                cur = cur->children[index];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
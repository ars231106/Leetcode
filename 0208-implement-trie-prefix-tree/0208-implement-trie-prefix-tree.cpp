class TrieNode{
public:
    TrieNode* child[26];
    bool end;

    TrieNode(){
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
        end = false;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(char c : word){
            int index = c - 'a';
            if(node->child[index] == NULL)
                node->child[index] = new TrieNode();
            node = node->child[index];
        }
        node->end = true;
    }

    bool search(string word){
        TrieNode* node = root;
        for(char c : word){
            int index = c - 'a';
            if(node->child[index] == NULL)
                return false;
            node = node->child[index];
        }
        return node->end;
    }

    bool startsWith(string prefix){
        TrieNode* node = root;
        for(char c : prefix){
            int index = c - 'a';
            if(node->child[index] == NULL)
                return false;
            node = node->child[index];
        }
        return true;
    }
};
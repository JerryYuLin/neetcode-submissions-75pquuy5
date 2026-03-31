class PrefixTree {
public:
    struct TrieNode {
        TrieNode* children[26]; 
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children[ch-'a']==nullptr){
                curr->children[ch-'a'] = new TrieNode();
            }

            if(i==word.size()-1) curr->isEnd = true;

            curr = curr->children[ch-'a'];
        }
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        
        for(int i=0; i<word.size();i++){
            char ch = word[i];

            if(curr->children[ch-'a']==nullptr || (i==word.size()-1 && !curr->isEnd)) return false;

            curr = curr->children[ch-'a'];
        }

        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(int i=0; i<prefix.size();i++){
            char ch = prefix[i];

            if(curr->children[ch-'a']==nullptr) return false;

            curr = curr->children[ch-'a'];
        }

        return true;
    }
};

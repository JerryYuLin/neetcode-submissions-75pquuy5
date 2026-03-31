class WordDictionary {
public:
    struct TrieNode{
        TrieNode *children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for(char c:word) {
            if (curr->children[c-'a'] == nullptr){
                curr->children[c-'a'] = new TrieNode();
            }

            curr = curr->children[c-'a'];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        stack<pair<TrieNode*, int>> node_stack;
        node_stack.emplace(root, 0);

        while(!node_stack.empty()){
            auto p = node_stack.top();
            TrieNode* node = p.first;
            int index = p.second;
            node_stack.pop();

            if(node == nullptr) continue;

            if(word[index] == '.'){
                if(index == word.size()-1){
                    for(TrieNode* n:node->children){
                        if(n != nullptr && n->isEnd) return true;
                    }
                }
                else if(index<word.size()-1){
                    for(TrieNode* n:node->children){
                        if(n!=nullptr){
                            node_stack.emplace(n, index+1);
                        }
                    }
                }
            }
            else if(node->children[word[index]-'a'] != nullptr) {
                if(index == word.size()-1 && node->children[word[index]-'a']->isEnd) return true;
                else if(index < word.size() - 1){
                    node_stack.emplace(node->children[word[index]-'a'], index+1);
                }
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
class TrieNode
{
public:    
    TrieNode():is_word(false),children(26,nullptr){}
    bool is_word;
    vector<TrieNode*> children;
    ~TrieNode()
    {
        for (TrieNode* child : children)
            if (child) delete child;
    }
};
class Trie 
{
    TrieNode* root_;
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root_ = new TrieNode();
    }
    const TrieNode* find(const string& prefix)
    {
        const TrieNode* p = root_;
        for (const char c : prefix)
        {
            p = p->children[c-'a'];
            if (p==nullptr) break;
        }
        return p;
    }
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        TrieNode* p = root_;
        for (const char c:word)
        {
            if (!p->children[c-'a'])
            {
                p->children[c-'a'] = new TrieNode();
            }
            p = p->children[c-'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        const TrieNode* p = find(word);
        return p&&p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        const TrieNode* p = find(prefix);
        return p!=nullptr;
    }
    //std::unique_ptr<TreeNode> root_;
};

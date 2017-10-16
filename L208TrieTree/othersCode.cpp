// Author: Huahua 
//注意这个code里对class的使用，以及const的用法。每当search时，他用的引导指针都带着const
// Running time: 99 ms
class Trie {
public:
    Trie(): root_(new TrieNode()) {}
    
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        TrieNode* p = root_.get();
        for (const char c : word) {
            if (!p->children[c - 'a'])//减去'a'就是获得了一个索引，就是0~26这几个数
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->is_word = true;//如果结点已存在，就不创建新node了，而是直接把P移到已有的位置上去
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) const {
        const TrieNode* p = find(word);
        return p && p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) const {
        return find(prefix) != nullptr;
    }
private:
    struct TrieNode {
        TrieNode():is_word(false), children(26, nullptr){}//children初始化成26个空指针
        //is_word判断是不是单词的结尾，初始化默认的是false。当遍历到最后一个char后，is_word会被设为true
        ~TrieNode() {//析构函数
            for (TrieNode* child : children)
                if (child) delete child;
        }
               
        bool is_word;
        vector<TrieNode*> children;
    };
    //从根节点走到当前Prefix结点，如果有这个prefix的话，返回prefix的这个结点，如果没有return nullptr
    const TrieNode* find(const string& prefix) const {
        const TrieNode* p = root_.get();//拿一个指针指向根节点
        for (const char c : prefix) {
            p = p->children[c - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }
    
    std::unique_ptr<TrieNode> root_;
};

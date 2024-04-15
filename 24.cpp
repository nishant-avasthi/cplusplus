#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    bool search(string key, bool prefix=false) {
        TrieNode *p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        if (prefix==false) return p->isWord;
        return true;
    }
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
class startclass{
    Trie trie;
    public:
    void start(){
        trie.insert("apple");
        cout<<(trie.search("apple")?"true":"false")<<endl;

        cout<<(trie.search("app")?"true":"false")<<endl;
        cout<<(trie.startsWith("app")?"true":"false")<<endl;
        trie.insert("app");
        cout<<(trie.search("app")?"true":"false")<<endl;
        
    }

};

int main(){
    startclass s;
    s.start();

    return 0;
}
/*
struct Node
{
    Node* links[26];
    bool flag;
    Node() : flag(false) {
        for (int i=0;i<26;i++)
        {
            links[i] = nullptr;
        }
    }
    bool containsKey(char ch)
    {
        return (nullptr != links[ch-'a']);
    }
    void putKey(char ch)
    {
        Node* node = new Node();
        links[ch - 'a'] = node;
    }
    Node* getNode(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd(void)
    {
        flag = true;
    }
    bool checkEnd(void)
    {
        return flag;
    }
};
 
class Trie
{
private:
    Node* root;
    void freeMemory(Node* node)
    {
        if (nullptr == node) return;
        for (int i=0;i<26;i++)
        {
            if (nullptr != node->links[i])
            {
                freeMemory(node->links[i]);
                node->links[i] = nullptr;
            }
        }
        delete node;
    }
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for (int i=0;i<word.size();i++)
        {
            if(false == node->containsKey(word[i]))
            {
                node->putKey(word[i]);
            }
            node = node->getNode(word[i]);
        }
        if(nullptr != node) node->setEnd();
    }
    bool search (string word) {
        Node* node = root;
        for (int i=0;i<word.size();i++)
        {
            if (false == node->containsKey(word[i])) return false;
            node = node->getNode(word[i]);
        }
        return node->checkEnd();
    }
    bool startsWith (string prefix)
    {
        Node* node = root;
        for (int i=0;i<prefix.size();i++)
        {
            if (false == node->containsKey(prefix[i])) return false;
            node = node->getNode(prefix[i]);
        }
        return true;
    }
    ~Trie()
    {
        freeMemory(root);
    }
};
 
int main(void)
{
    Trie trie;
    vector<string> words = {
        "anil",
        "animal",
        "ant",
        "apple",
        "ape",
        // "app"
    };
    for (const string& word:words)
    {
        trie.insert(word);
    }
 
    cout << "word " << words[2] << ": " << trie.search(words[2]) << endl;
    cout << "starts with an: " << " " << trie.startsWith("an") << endl;
    cout << "starts with api: " << " " << trie.startsWith("api") << endl;
    cout << "word antenna: " << ": " << trie.startsWith("antenna") << endl;
    cout << "starts with app: " << " " << trie.startsWith("app") << endl;
    cout << "word app: " << ": " << trie.search("app") << endl;
    return 0;
}

*/
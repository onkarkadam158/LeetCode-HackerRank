class Node{
private:
    unordered_map<char,Node*>links;
    bool flag=false;
public:
    bool isAdded(char ch){
        if(links.find(ch)==links.end()) return false;
        return true;
    }
    void addNewNode(char ch,Node* node){
        links[ch]=node;
    }
    Node* getNextNode(char ch){
        return links[ch];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root= new Node();
    }
    void insertToTrie(string &word){
        Node* node= root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                node->addNewNode(ch,new Node());
            }
            node=node->getNextNode(ch);
        }
        node->setEnd();
    }
    bool search(string &word){
        Node* node=root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                return false;
            }
            node=node->getNextNode(ch);
        }
        return node->isEnd();
    }
};

class MagicDictionary {
public:
    Trie trie;
    MagicDictionary() {

    }
    void buildDict(vector<string> dictionary) {
        for(auto str:dictionary){
            trie.insertToTrie(str);
        }
    }
    
    bool search(string searchWord) {
        for(auto &ch:searchWord){
            char original=ch;
            for(int i=0;i<26;i++){
                char temp='a'+i;
                if(temp!=original){
                    ch=temp;
                    if(trie.search(searchWord)) return true;
                }
            }
            ch=original;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
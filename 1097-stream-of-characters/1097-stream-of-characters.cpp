class Node{
private:
    unordered_map<char,Node*>mp;
    bool flag=false;
public:
    bool isAdded(char ch){
        return (mp.find(ch)!=mp.end());
    }
    void addNewNode(char ch,Node* node){
        mp[ch]=node;
    }
    Node* getNextNode(char ch){
        return mp[ch];
    }
    void setEnd(){
        flag =true;
    }
    bool getEnd(){
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
    void insert(string &word){
        Node* node=root;
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
                return node->getEnd();
            }
            node=node->getNextNode(ch);
            if(node->getEnd()) return true;
        }
        return node->getEnd();
    }
};
class StreamChecker {
public:
    Trie trie;
    string stream="";
    int maxLength=0;
    StreamChecker(vector<string>& words) {
        for(auto &word:words){
            reverse(word.begin(),word.end());
            trie.insert(word);
            maxLength=max(maxLength,int(word.size()));
        }
    }
    
    bool query(char letter) {
        stream=letter+stream;
        // stream = stream.substr(0,maxLength);
        if(stream.size()>maxLength){
            stream.pop_back();
        }
        return trie.search(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
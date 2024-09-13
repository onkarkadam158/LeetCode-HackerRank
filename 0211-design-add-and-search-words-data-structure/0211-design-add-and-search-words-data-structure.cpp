class Node{
    public:
        unordered_map<char,Node*>links;
        bool flag=false;
        bool isAdded(char ch){
            if(links.find(ch)!=links.end()) return true;
            return false;
        }
        void addWord(char ch,Node* node){
            links[ch]=node;
        }
        Node* getNext(char ch){
            return links[ch];
        }
        void setEndOfWord(){
            flag=true;
        }
        bool isEnd(){
            return flag;
        }
        bool isDotCharExists(){
            if(links.find('.')!=links.end()) return true;
            return false;
        }
};  
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                node->addWord(ch,new Node());
            }
            node=node->getNext(ch);
        }
        node->setEndOfWord();
    }
    
    bool search(string word) {
        Node* node = root;
        return searchDFS(node,0,word);
    }
    bool searchDFS(Node* node,int ind,string &word){
        if(ind==word.size()){
            return node->isEnd();
        }
        if(word[ind]=='.'){
            for(auto link:node->links){
                bool temp=searchDFS(link.second,ind+1,word);
                if(temp) return true;
            }
        }
        if(!node->isAdded(word[ind])) return false;
        return searchDFS(node->getNext(word[ind]),ind+1,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
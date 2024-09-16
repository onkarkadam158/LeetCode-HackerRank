class Node{
    private:
    public:
    map<char,Node*>links;
    bool flag=false;
    bool isAdded(char ch){
        if(links.find(ch)==links.end()) return false;
        return true;
    }
    void Add(char ch,Node* node){
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
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insertToTrie(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isAdded(word[i])){
                node->Add(word[i],new Node());
            }
            node=node->getNextNode(word[i]);
        }
        node->setEnd();
    }
    void searchWord(string word,vector<string>&sug){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isAdded(word[i])){
                return ;
            }
            node=node->getNextNode(word[i]);
        }
        getThreeWords(node,word,sug);
    }
    void getThreeWords(Node* node,string& word,vector<string>&sug){
        if(sug.size()>=3) return ;
        if(node->isEnd()){
            sug.push_back(word);
        }
        for(auto a:node->links){
            word+=a.first;
            getThreeWords(node->getNextNode(a.first),word,sug);
            word.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for(auto prod:products){
            trie.insertToTrie(prod);
        }
        int n=searchWord.size();
        vector<vector<string>> res;
        string temp="";
        for(char ch:searchWord){
            vector<string>sug;
            temp+=ch;
            trie.searchWord(temp,sug);
            res.push_back(sug);

        }
        return res;
    }
};
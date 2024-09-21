class Node{
    unordered_map<char,Node*>arr;
    bool flag=false;
    public:
    bool isAdded(char ch){
        return arr.find(ch)!=arr.end();
    }
    void addNew(char ch,Node*node){
        arr[ch]=node;
    }
    Node* getNext(char ch){
        return arr[ch];
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
        root= new Node();
    }
    void insert(string &word){
        Node* node=root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                node->addNew(ch,new Node());
            }
            node=node->getNext(ch);
        }
        node->setEnd();
    }
    void search(vector<int>&res){
        Node* node=root;
        string wrd="";
        dfs(root,res,wrd);
    }
    void dfs(Node* node,vector<int>&res,string& word){
        if(node->isEnd()){
            res.push_back(stoi(word));
        }
        for(int i=0;i<=9;i++){
            char ch=('0'+i);
            if(node->isAdded(ch)){
                word+=ch;
                dfs(node->getNext(ch),res,word);
                word.pop_back();
            }
        }
    }

};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie trie;
        for(int i=1;i<=n;i++){
            string num=to_string(i);
            cout<<num<<" ";
            trie.insert(num);
        }
        vector<int>res;

        trie.search(res);
        
        return res;
    }
};
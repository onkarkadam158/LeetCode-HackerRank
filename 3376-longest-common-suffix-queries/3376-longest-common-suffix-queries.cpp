class Node{
public:
    map<char,Node*>mp;
    int index=-1;
    int size=0;

    bool isAdded(char ch){
        return mp.find(ch)!=mp.end();
    }
    void addNewNode(char ch,Node* node){
        mp[ch]=node;
    }
    Node* getNext(char ch){
        return mp[ch];
    }
    void setEnd(int ind,int sz){
        index=ind;
        size=sz;
    }
    int getIndex(){
        return index;
    }
    int getSize(){
        return size;
    }
    bool isEnd(){
        return index!=-1;
    }
    Node* getNextFirst(){
        for(auto a:mp){
            return a.second;
        }
        return NULL;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root= new Node();
    }
    void insert(string & word,int ind,int size){
        Node* node=root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                node->addNewNode(ch,new Node());
            }
            node=node->getNext(ch);
        }
        if(!node->isEnd())
            node->setEnd(ind,size);
    }
    int getSearch(string & word){
        Node* node=root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                break;
            }
            node=node->getNext(ch);
        }
        pair<int,int>temp= getMini(node);
        return temp.first;
    }
    pair<int,int> getMini(Node* node){
        if(node->isEnd()){
            return {node->getIndex(),node->getSize()};
        }
        pair<int,int> res={1e5,1e5};
        for(auto a:node->mp){
            pair<int,int> temp=getMini(a.second);
            if(temp.second<res.second){
                res=temp;
            }
            else if(temp.second==res.second){
                if(temp.first<res.first){
                    res=temp;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    void reverseArr(vector<string>&arr){
        for(auto &a:arr){
            reverse(a.begin(),a.end());
        }
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        reverseArr(wordsContainer);
        reverseArr(wordsQuery);
        Trie trie;
        for(int i=0;i<wordsContainer.size();i++){
            trie.insert(wordsContainer[i],i,wordsContainer[i].size());
        }
        vector<int>res;
        for(auto word:wordsQuery){
            int temp=trie.getSearch(word);
            res.push_back(temp);
        }
        return res;
    }
};
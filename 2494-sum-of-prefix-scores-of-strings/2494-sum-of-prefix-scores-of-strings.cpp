class Node{
    Node* links[26];
    int count=0;
public:
    bool isAdded(char ch){
        return links[ch-'a']!=NULL;
    }
    void addNewNode(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* getNext(char ch){
        return links[ch-'a'];
    }
    int getCount(){
        return count;
    }
    void addCount(){
        count++;
    }
};
class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string& word){
        Node* node=root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                node->addNewNode(ch,new Node());
            }
            node=node->getNext(ch);
            node->addCount();
        }
    }
    int search(string &word){
        Node* node=root;
        int sum=0;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                return 0;
            }
            node=node->getNext(ch);
            sum+=node->getCount();
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto str:words){
            trie.insert(str);
        }
        int n=words.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            // string temp="";
            // for(int j=0;j<words[i].size();j++){
            //     temp+=words[i][j];
            //     result[i]+=trie.search(temp);
            // }

            result[i]=trie.search(words[i]);
        }
        return result;
    }
};
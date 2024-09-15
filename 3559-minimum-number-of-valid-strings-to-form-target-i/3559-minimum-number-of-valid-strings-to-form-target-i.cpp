class Node {
    Node * links[26];
    bool flag =false;
public:
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put (char ch,Node* node){
        links[ch-'a']=node;

    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
public:   
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    int search(string &word,int k,int n,vector<int>&dp) {
        if(k==n) return 0;
        if(dp[k]!=-1) return dp[k];
        Node* node = root;
        int ans=1e7;
        for(int i=k;i<n;i++){
            if(!node->containsKey(word[i])){
                break;
            }
            ans=min(ans,1+search(word,i+1,n,dp));
            node=node->get(word[i]);
        }
        return dp[k]=ans;
    }
};
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie trie;
        for(auto a:words){
            trie.insert(a);
        }
        int n=target.size();
        vector<int>dp(n+1,-1);
        int ans= trie.search(target,0,n,dp);    
        if(ans>1e6) return -1;
        return ans;
    }
};
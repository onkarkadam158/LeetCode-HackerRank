class Node{
    private:
    unordered_map<char,Node*>mp;
    bool flag=false;
    public:
    bool isAdded(char ch){
        return mp.find(ch)!=mp.end();
    }
    void addNewNode(char ch,Node* node){
        mp[ch]=node;
    }
    Node* getNextNode(char ch){
        return mp[ch];
    }
    void setEnd(){
        flag=true;
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
                node->addNewNode(ch,new Node());
            }
            node=node->getNextNode(ch);
        }
        return node->getEnd();
    }
    void freeNodes(){
        fun(root);
    }
    void fun(Node* node){
        for(char ch='a';ch<='z';ch++){
            if(node->isAdded(ch)){
               fun(node->getNextNode(ch));
            }
        }
        delete node;
    }
    
};

class Solution {
public: 
    Trie trie;
    int bruteforce(int i,int n,string& s,unordered_map<string ,int>&mp){
        if(i>=n) return 0;
        string str="";
        int res=0;
        for(int ind=i;ind<n;ind++){
            str+=s[ind];
            if(mp.find(str)!=mp.end()){
                int temp=ind-i+1+bruteforce(ind+1,n,s,mp);
                res=max(res,temp);
            }
        }
        int temp1=bruteforce(i+1,n,s,mp);
        return max(temp1,res);
    }
    int memoization(int i,int n,string& s,unordered_map<string ,int>&mp,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        string str="";
        int res=0;
        for(int ind=i;ind<n;ind++){
            str+=s[ind];
            if(mp.find(str)!=mp.end()){
                int temp=ind-i+1+memoization(ind+1,n,s,mp,dp);
                res=max(res,temp);
            }
        }
        int temp1=memoization(i+1,n,s,mp,dp);
        return dp[i]=max(temp1,res);
    }
    
    int OptimalMemoizationUsingTrie(int i,int n,string& s,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        string str="";
        int res=0;
        for(int ind=i;ind<n;ind++){
            str+=s[ind];
            if(trie.search(str)){
                int temp=ind-i+1+OptimalMemoizationUsingTrie(ind+1,n,s,dp);
                res=max(res,temp);
            }
        }
        int temp1=OptimalMemoizationUsingTrie(i+1,n,s,dp);
        return dp[i]=max(temp1,res);
    }
    int  minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();    
        // unordered_map<string,int>mp;
        // for(auto a:dictionary){
        //     mp[a]++;
        // }

        //bruteforce solution Exponential time 
        // return n-bruteforce(0,n,s,mp);

        
        //memoization solution linear time 
        // vector<int>dp(n+1,-1);
        // return n-memoization(0,n,s,mp,dp);

        //Using Trie + memoization solution
        vector<int>dp(n+1,-1);
        for(auto word:dictionary){
            trie.insert(word);
        }
        int answer = n- OptimalMemoizationUsingTrie(0,n,s,dp);
        trie.freeNodes();
        return answer;
    }
};














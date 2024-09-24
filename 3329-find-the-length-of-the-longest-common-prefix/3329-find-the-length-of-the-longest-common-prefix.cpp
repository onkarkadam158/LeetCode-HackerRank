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
    void insert(string word){
        Node* node=root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                node->addNewNode(ch,new Node());
            }
            node=node->getNextNode(ch);
        }
        node->setEnd();
    }
    int search(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(!node->isAdded(ch)){
                return i;
            }
            node=node->getNextNode(ch);
        }
        return word.size();
    }
    
};
class Solution {
public:
    unordered_map<string,int>getAllPrefixes(vector<int>&arr1){
        unordered_map<string,int>res;
        for(auto a:arr1){
            string temp=to_string(a);
            string t="";
            for(int i=0;i<temp.size();i++){
                t=t+temp[i];
                res[t]++;
            }
        }
        return res;
    }
    int hashMapSolution(vector<int>& arr1, vector<int>& arr2){
        int count=0,n=arr1.size(),m=arr2.size();
        unordered_map<string,int>mp1;
        mp1=getAllPrefixes(arr1);
        for(auto a:arr2){
            string temp=to_string(a);
            string t="";
            for(int i=0;i<temp.size();i++){
                t=t+temp[i];
                if(mp1.find(t)!=mp1.end()){
                    count=max(count,int(t.size()));
                }
            }
        }
        return count;
    }
    int TrieSolution(vector<int>& arr1, vector<int>& arr2){
        Trie trie;
        for(auto num:arr1){
            trie.insert(to_string(num));
        }
        int res=0;
        for(auto num:arr2){
            int temp=trie.search(to_string(num));
            res=max(res,temp);
        }
        return res;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        return hashMapSolution(arr1,arr2);

        return TrieSolution(arr1,arr2);
    }
};
class Node{
private:
    unordered_map<char,Node*>mp;
    bool end=false;
public:
    bool nextExists(char ch){
        return mp.find(ch)==mp.end();
    }
    Node* getNext(char ch){
        return mp[ch];
    }    
    void addNode(char ch,Node* node){
        mp[ch]=node;
    }
    bool isEnd(){
        return end;
    }
    void setEnd(){
        end=true;
    }
};
class Trie{
public:
    Node* root;
    void addToTrie(string&word){
        Node* node=root;

    }
    void search(string&word){
        Node* node=root;
        
    }
};
class Solution {
public:
    vector<string> solution1(vector<string>& folder) {
        unordered_map<string,int>mp;
        for(auto a:folder){
            mp[a]++;
        }
        vector<string>res;
        for(auto str:folder){
            int j=str.size()-1;
            bool flag=true;
            while(str[j]!='/')j--;
            while(j>0){
                if(str[j]=='/' and mp.find(str.substr(0,j)) != mp.end()  ){
                    flag=false;
                    break;
                }
                j--;
            }
            if(flag) res.push_back(str);
        }
        return res;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        return solution1(folder);
    }
};
class Node{
private:
    unordered_map<char,Node* >links;
    bool flag= false;
public:
    bool isAdded(char ch){
        if(links.find(ch)!=links.end()) return true;
        return false;
    }
    void addNewNode(char ch,Node* node){
        links[ch]=node;
    }
    Node* getNextNode(char ch){
        return links[ch];
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
    void insert(string& word){
        Node* node=root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                node->addNewNode(ch,new Node());
            }
            node=node->getNextNode(ch);
        }
        node->setEnd();
    }
    bool search(string& word){
        Node* node=root;
        for(auto ch:word){
            if(!node->isAdded(ch)){
                return false;
            }
            node=node->getNextNode(ch);
            if(node->getEnd() == false) return false;
        }
        return node->getEnd();
    }
};

class Solution {
public:
    bool static comp(const string &s1,const string &s2){
        if(s1.size()!=s2.size()) return s1.size()>s2.size();
        return (s1<s2);
    }
    string bruteforce(vector<string>& words){
        unordered_map<string,int>mp;
        for(auto word:words){
            mp[word]++;
        }
        sort(words.begin(),words.end(),comp);
        for(auto word:words){
            string temp="";
            int count=0;
            for(auto ch:word){
                temp+=ch;
                if(mp.find(temp)!=mp.end()) count++;
            }
            if(count==word.size()) return word;
        }
        return "";
    }
    string longestWord(vector<string>& words) {
        // return bruteforce(words);// Time (O(words*wordlen)) space O(words*wordlen)

        Trie trie;
        sort(words.begin(),words.end(),comp);
        for(auto word:words){
            trie.insert(word);
        }
        for(auto word:words){
            if(trie.search(word)) return word;
        }
        return "";
    }
};
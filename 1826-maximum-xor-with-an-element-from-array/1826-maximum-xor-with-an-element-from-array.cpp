class Node{
private:
    Node* links[2];
public:
    bool isAdded(int bit){
        return links[bit]!=NULL;
    }
    void addNewNode(int bit,Node* node){
        links[bit]=node;
    }
    Node* getNextNode(int bit){
        return links[bit];
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root= new Node();
    }
    void insertIntoTrie(int num){
        Node* node=root;
        for(int k=31;k>=0;k--){
            int bit=(num>>k)&1;
            if(!node->isAdded(bit)){
                node->addNewNode(bit,new Node());
            }
            node=node->getNextNode(bit);
        }
    }
    int getMaxXor(int x,int m){
        Node* node=root;
        int result=0;
        for(int k=31;k>=0;k--){
            int bit=(x>>k)&1;
            if(node->isAdded(!bit)){
                result+=(1<<k);
                node=node->getNextNode(!bit);
            }
            else if(node->isAdded(bit)){
                node=node->getNextNode(bit);
            }
            else {
                return -1;
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> bruteforce(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size(),n=nums.size();
        vector<int>result(m,-1);
        for(int i=0;i<m;i++){
            int x=queries[i][0],m=queries[i][1];
            for(auto num:nums){
                if(num<=m){
                    result[i]=max(result[i],num^x);
                }
            }
        }
        return result;
    }
    static bool sortcol(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // return bruteforce(nums,queries);
        sort(nums.begin(),nums.end());
        Trie trie;
        int m=queries.size(),k=0,n=nums.size();
        for(int i=0;i<m;i++){
            queries[i].push_back(i);
        }
        vector<int>res(m,-1);
        sort(queries.begin(),queries.end(),sortcol);
        for(int i=0;i<m;i++){
            int xi=queries[i][0],mi=queries[i][1],ind=queries[i][2];
            for(int j=k;j<n;j++){
                if(nums[j]<=mi){
                    trie.insertIntoTrie(nums[j]);
                }
                else{
                    k=j;
                    break;
                }
            }
            int temp=trie.getMaxXor(xi,mi);
            res[ind]=max(res[ind],temp);
        }
        return res;
    }
};
class Node{
private:
    Node* links[2];
public:
    bool isAdded(int bit){
        return links[bit]!=NULL;
    }
    void addNextNode(int bit,Node* node){
        links[bit]=node;
    }
    Node* getNextNode(int bit){
        return links[bit];
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void addToTrie(int num){
        Node* node=root;
        //iterate over all the bits from MSB to LSB
        for(int k=31;k>=0;k--){
            int bit=(num>>k)&1; //get k^th bit
            if(!node->isAdded(bit)){
                node->addNextNode(bit,new Node());
            }
            node=node->getNextNode(bit);
        }
    }
    int getMaximum(int num){
        Node* node=root;
        int result=0;
        for(int k=31;k>=0;k--){
            int bit=(num>>k)&1; //get k^th bit
            if(node->isAdded(!bit)){
                result+=(1<<k);
                node=node->getNextNode(!bit);
            }
            else{
                node=node->getNextNode(bit);
            }
        }
        return result;
    }

};

class Solution {
public:
    int bruteforce(vector<int>&nums){
        int res=0,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res=max(res,nums[i]^nums[j]);
            }
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        // return bruteforce(nums); o(n^2) time give TLE O(1)space'
        int n=nums.size();
        Trie trie;
        for(int i=0;i<n;i++){
            trie.addToTrie(nums[i]);
        }
        int result=0;
        for(auto a:nums){
            int temp=trie.getMaximum(a);
            result=max(result,temp);
        }
        return result;

    }
};
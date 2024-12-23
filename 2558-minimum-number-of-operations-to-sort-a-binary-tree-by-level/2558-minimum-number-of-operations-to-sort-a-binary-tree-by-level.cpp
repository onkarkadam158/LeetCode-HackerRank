/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countswap(vector<int> &temp){
        int n=temp.size();
        vector<int>sorted=temp;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[sorted[i]]=i;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(temp[i]==sorted[i]) continue;
            while(temp[i]!=sorted[i]){
                int ele=temp[i];
                int ind=mp[ele];
                swap(temp[i],temp[ind]);
                count++;
            }
        }
        return (count);
    }
    int minimumOperations(TreeNode* root) {
        int res=0;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int sz=que.size();
            vector<int>temp;
            for(int i=0;i<sz;i++){
                TreeNode* curr=que.front();
                temp.push_back(curr->val);
                if(curr->left) {que.push(curr->left);}
                if(curr->right) {que.push(curr->right);}
                que.pop();
            }
            res+=countswap(temp);
        }
        return res;
    }
};




















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
    void printAdj(unordered_map<int,vector<pair<int,int>>>&adj){
        for(auto a:adj){
            cout<<a.first<<"\n";
            for(auto x:a.second){
                cout<<x.first<<" "<<x.second<<"\n";
            }
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int>indegree;
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto a:descriptions){
            indegree[a[0]]=0;
        }
        for(auto a:descriptions){
            indegree[a[1]]++;
            adj[a[0]].push_back({a[1],a[2]});
        }
        queue<int>que;
        for(auto a:indegree){
            if(a.second==0)que.push(a.first);
        }
        TreeNode* root = new TreeNode(que.front());
        unordered_map<int,TreeNode*>mp;
        mp[que.front()]=root;
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            for(auto neighbor:adj[curr]){
                int node=neighbor.first,isLeft=neighbor.second;
                indegree[node]--;
                if(indegree[node]==0) que.push(node);
                TreeNode* temp=new TreeNode(node);
                mp[node]=temp;
                if(isLeft) {
                    mp[curr]->left=temp;
                }
                else{
                    mp[curr]->right=temp;
                }
            }
        }
        return root;
    }
};
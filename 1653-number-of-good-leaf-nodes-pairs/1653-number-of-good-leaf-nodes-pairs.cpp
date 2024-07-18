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
    void getParents(TreeNode* root,TreeNode* prev,unordered_map<TreeNode*,TreeNode*>&parents, vector<TreeNode*>&leafs){
        if(!root) return ;
        getParents(root->left,root,parents,leafs);
        parents[root]=prev;
        if(!root->left and !root->right){
            // leaf node
            leafs.push_back(root);
        }
        getParents(root->right,root,parents,leafs);
    }
    int getCountOfLeafNodesLessThanDist(TreeNode* src,vector<TreeNode*>&leafs,int dist,unordered_map<TreeNode*,TreeNode*>&parents){
        queue<TreeNode*>que;
        que.push(src);
        unordered_map<TreeNode*,int>vis;
        vis[src]=1;
        int level=1;
        while(!que.empty()){
            int size=que.size();
            if(level>dist) break;
            while(size--){
                TreeNode* curr=que.front();
                que.pop();
                if(curr->left and vis.find(curr->left)==vis.end()){
                    que.push(curr->left);
                    vis[curr->left]=level;
                }
                if(curr->right  and vis.find(curr->right)==vis.end()){
                    que.push(curr->right);
                    vis[curr->right]=level;
                }
                if(parents[curr]  and vis.find(parents[curr])==vis.end()){
                    que.push(parents[curr]);
                    vis[parents[curr]]=level;
                }
            }
            level++;
            
        }
        int count=0;
        for(auto a:leafs){
            if(src!=a and vis.find(a)!=vis.end() and vis[a]<=dist) count++;
        }
        return count;
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,TreeNode*>parents;
        vector<TreeNode*>leafs;
        getParents(root,NULL,parents,leafs);
        int count=0,n=leafs.size();
        for(int i=0;i<n;i++){
            count+=getCountOfLeafNodesLessThanDist(leafs[i],leafs,distance,parents);
        }
        return count/2;
    }
};
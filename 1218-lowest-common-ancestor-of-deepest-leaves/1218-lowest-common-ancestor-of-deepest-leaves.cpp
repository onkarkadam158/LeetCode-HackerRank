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

    vector<TreeNode*> getLeafs(TreeNode* root) {
        vector<TreeNode*> leafs;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            vector<TreeNode*>temp;
            int size=que.size();
            while(size--){
                TreeNode* curr= que.front();
                temp.push_back(curr);
                que.pop();
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            leafs=temp;
        }
        return leafs;
    }
    bool getPath(TreeNode* root,TreeNode* node,vector<TreeNode*>&temp,vector<vector<TreeNode*>> &paths){
        if(!root) return false;

        temp.push_back(root);

        if(root==node){
            paths.push_back(temp);
            return true;
        }
        if(getPath(root->left,node,temp,paths)) return true;

        if(getPath(root->right,node,temp,paths)) return true;

        temp.pop_back();
        return false;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        vector<TreeNode*> leafs = getLeafs(root);
        vector<vector<TreeNode*>> paths;
        for(auto node:leafs){
            vector<TreeNode*>temp;
            getPath(root,node,temp,paths);
        }
        int n=paths.size();
        int m=paths[0].size();
        for(int j=m-1;j>=0;j--){
            int count=0;
            TreeNode* node=paths[0][j];
            for(int i=0;i<n;i++){
                if(node==paths[i][j]) count++;
            }
            if(count==n){
                return paths[0][j];
            }
        }
        return NULL;
    }
};
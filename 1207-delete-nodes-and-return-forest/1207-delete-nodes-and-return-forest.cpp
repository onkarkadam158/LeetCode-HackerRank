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
    TreeNode* solve(TreeNode* root,vector<TreeNode*>&res,unordered_map<int,int>&mp){
        if(!root) return NULL;
        root->left=solve(root->left,res,mp);
        root->right=solve(root->right,res,mp);
        if(mp.find(root->val)!=mp.end()){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int>mp;
        for(auto a:to_delete)mp[a]++;
        vector<TreeNode*>res;
        solve(root,res,mp);
        if(mp.find(root->val)==mp.end()) res.push_back(root);
        return res;
    }
};
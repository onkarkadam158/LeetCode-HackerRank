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
    int n;
    unordered_map<int,int>mp;
    TreeNode* solve(int i,int j,int x,vector<int>& preorder, vector<int>& inorder) {
        if(i>j or x>=n ){
            return NULL;
        }

        int num=preorder[x];
        int inIndex=mp[num];
        TreeNode* node = new TreeNode(num);

        int leftEle=inIndex-i;

        node->left=solve(i,inIndex-1,x+1,preorder,inorder);
        node->right=solve(inIndex+1,j,x+leftEle+1,preorder,inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n=preorder.size();
        mp.clear();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return solve(0,n-1,0,preorder,inorder);
    }
};
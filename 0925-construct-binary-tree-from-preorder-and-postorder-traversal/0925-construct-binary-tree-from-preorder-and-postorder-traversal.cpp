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
    TreeNode* solve(int start,int end,int postStart,int postEnd,vector<int>& preorder, vector<int>& postorder){
        if(start<0 or end>= preorder.size() or start>end) return NULL;
        if(postStart<0 or postEnd>= preorder.size() or postStart>postEnd) return NULL;
        
        int num=preorder[start];
        
        TreeNode* node= new TreeNode(num);

        if((start+1)>end) return node;
        int leftNode=preorder[start+1];

        int mid=mp[leftNode];

        int numEleToLeft=mid-postStart+1;
        node->left=solve(start+1,start+numEleToLeft,postStart,mid,preorder,postorder);
        node->right=solve(start+numEleToLeft+1,end,mid+1,postEnd-1,preorder,postorder);

        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        n=preorder.size();
        mp.clear();
        for(int i=0;i<n;i++){
            mp[postorder[i]]=i;;
        }
        return solve(0,n-1,0,n-1,preorder,postorder);
    }
};
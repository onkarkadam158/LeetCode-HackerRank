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
    TreeNode* solve(int &ind,int n,int depth,string& traversal){
        if(ind>=n) {
            return NULL;
        }
        int i=ind;
        while(i<n and traversal[i]=='-'){
            i++;
        }
        if(depth!=((i-ind))) return NULL;
        int num=0;
        while(i<n and traversal[i]<='9' and traversal[i]>='0'){
            num=num*10+(traversal[i]-'0');
            i++;
        }
        ind=i;
        TreeNode* node=new TreeNode(num);

        node->left=solve(ind,n,depth+1,traversal);  
        node->right=solve(ind,n,depth+1,traversal);  

        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.size();
        int depth=0, ind=0;
        return solve(ind,n,depth,traversal);

    }
};
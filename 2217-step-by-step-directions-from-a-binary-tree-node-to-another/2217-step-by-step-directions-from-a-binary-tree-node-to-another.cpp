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
    void getParents(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* root,TreeNode* prev){
        if(!root) return ;
        getParents(parent,root->left,root);
        parent[root]=prev;
        getParents(parent,root->right,root);
    }
    TreeNode* inorder(TreeNode* root,int value){
        if(!root) return NULL;
        TreeNode* left=inorder(root->left,value);
        if(left) return left;
        if(root->val==value) return root;
        TreeNode* right=inorder(root->right,value);
        if(right) return right;
        return NULL;
    }
    string Solution1(TreeNode* root, int startValue, int destValue){
        unordered_map<TreeNode*,TreeNode*>parents;
        getParents(parents,root,NULL);

        TreeNode* start=inorder(root,startValue);
        TreeNode* end=inorder(root,destValue);

        unordered_map<TreeNode*,string>path;
        queue<TreeNode*>que;
        que.push(start);
        path[start]="";
        while(!que.empty()){
            TreeNode* curr=que.front();
            que.pop();
            if(curr==end) return path[curr];
            string currPath=path[curr];
            TreeNode* parent=parents[curr],*left=curr->left,*right=curr->right;
            if(parent and path.find(parent)==path.end()){
                que.push(parent);
                path[parent]=currPath+"U";
            }
            if(left and path.find(left)==path.end()){
                que.push(left);
                path[left]=currPath+"L";
            }
            if(right and path.find(right)==path.end()){
                que.push(right);
                path[right]=currPath+"R";
            }
        }
        return path[end];
    }
    void LowestCommonAncestor(TreeNode* root,int start,int end,char prev,vector<pair<TreeNode*,char>>&pathToAncestor ,vector<pair<TreeNode*,char>>&pathFromAcestor){
        if(!root) return ;

        pathToAncestor.push_back({root,prev});
        pathFromAcestor.push_back({root,prev});

        LowestCommonAncestor(root->left,start,end,'L',pathToAncestor,pathFromAcestor);
        LowestCommonAncestor(root->right,start,end,'R',pathToAncestor,pathFromAcestor);

        if(pathToAncestor.size()>0 and pathToAncestor[pathToAncestor.size()-1].first->val !=start) pathToAncestor.pop_back();
        if(pathFromAcestor.size()>0 and pathFromAcestor[pathFromAcestor.size()-1].first->val !=end) pathFromAcestor.pop_back();
    }
    string Solution2(TreeNode* root, int startValue, int destValue){
        vector<pair<TreeNode*,char>>pathToAncestor,pathFromAcestor;

        LowestCommonAncestor(root,startValue,destValue,'U',pathToAncestor,pathFromAcestor);
        string path="";
        int n=pathToAncestor.size(),m=pathFromAcestor.size(),index=0;
        for(int i=0;i<min(m,n);i++){
            if(pathToAncestor[i].first==pathFromAcestor[i].first){
                index=i;
            }
        }
        for(int j=index+1;j<n;j++){path+="U";}
        for(int j=index+1;j<m;j++){path+=pathFromAcestor[j].second;}
        return path;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // return Solution1(root,startValue,destValue); // gives memory limit exceed error 

        return Solution2(root,startValue,destValue);
    }
};
























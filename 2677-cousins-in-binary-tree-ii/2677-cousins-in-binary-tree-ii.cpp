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
// ---------------------------------         Solution1      -------------------------------------
    TreeNode* solution1(TreeNode* root){
        queue<pair<TreeNode*,TreeNode*>>que; //queue of pair of <node,parent>
        que.push({root,NULL});
        vector<int>res;
        while(!que.empty()){
            int sz=que.size();
            vector<pair<TreeNode*,TreeNode*>>arr;
            while(sz--){
                TreeNode* currNode = que.front().first;
                arr.push_back(que.front());
                que.pop();
                if(currNode->left) que.push({currNode->left,currNode});
                if(currNode->right) que.push({currNode->right,currNode});
            }
            for(auto curr:arr){
                int sum=0;
                for(auto curr1:arr){
                    if(curr.first!=curr1.first and curr.second!=curr1.second){
                        sum+=curr1.first->val;
                    }
                }
                res.push_back(sum);
            }
        }
        queue<TreeNode*>que1;
        que1.push(root);
        int i=0;
        while(!que1.empty()){
            int sz=que1.size();
            while(sz--){
                TreeNode* currNode = que1.front();
                currNode->val=res[i++];
                que1.pop();
                if(currNode->left) que1.push(currNode->left);
                if(currNode->right) que1.push(currNode->right);
            }
        }
        return root;
    }
    // ----------------------------  Solution 2 ----------------------------------------------------------------
    int getSibling(TreeNode* root,TreeNode* parent){
        if(!parent) return 0;
        if(parent->left==root){
            return parent->right ? parent->right->val : 0;
        }
        if(parent->right==root){
            return parent->left ? parent->left->val : 0;
        }
        return 0;
    }
    void inorder(TreeNode* root,TreeNode* parent,vector<int>&res,int level, vector<int>&newNodes){
        if(!root) return ;
        inorder(root->left,root,res,level+1,newNodes);
        int currNodeVal=root->val;
        int siblingNodeVal = getSibling(root,parent);
        newNodes.push_back(res[level]- currNodeVal - siblingNodeVal);
        // cout<<res[level]- currNodeVal - siblingNodeVal<<" ";
        inorder(root->right,root,res,level+1,newNodes);
    }
    int i=0;
    void inorder1(TreeNode* root, vector<int>&newNodes){
        if(!root) return ;
        inorder1(root->left,newNodes);
        root->val=newNodes[i++];
        inorder1(root->right,newNodes);
    }
    TreeNode* solution2(TreeNode* root) {
        queue<TreeNode*>que1;
        que1.push(root);
        vector<int>res;
        while(!que1.empty()){
            int sz=que1.size();
            int sum=0;
            while(sz--){
                TreeNode* currNode = que1.front();
                sum+=currNode->val;
                que1.pop();
                if(currNode->left) que1.push(currNode->left);
                if(currNode->right) que1.push(currNode->right);
            }
            res.push_back(sum);
        }
        int level=0;
        vector<int>newNodes;
        inorder(root,NULL,res,level, newNodes);
        inorder1(root,newNodes);
        return root;
    }
    //----------------------------------------  Solution 3  -----------------------------------------------------------
    TreeNode* solution3(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        vector<int>res;
        while(!que.empty()){
            int sz=que.size();
            int levelSum=0;
            while(sz--){
                TreeNode* currNode = que.front();
                levelSum+=currNode->val;
                que.pop();
                if(currNode->left) que.push(currNode->left);
                if(currNode->right) que.push(currNode->right);
            }
            res.push_back(levelSum);
        }
        //second iteration on tree
        que.push(root);
        res.push_back(0);
        root->val=0;
        int level=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                TreeNode* curr=que.front();
                que.pop();
                int levelSum=res[level+1];
                int sibSum=0;
                if(curr->left) sibSum+=curr->left->val;
                if(curr->right) sibSum+=curr->right->val;

                if(curr->left) {
                    que.push(curr->left);
                    curr->left->val=levelSum-sibSum;
                }   
                if(curr->right){
                    que.push(curr->right);
                    curr->right->val=levelSum-sibSum;
                }
            }
            level++;
        }
        return root;
    }
    // --------------------------------------------------- Solution 4 ---------------------------------------------------

    TreeNode* solution4(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        int nextSum=0,currSum=0;
        while(!que.empty()){
            int size=que.size();
            nextSum=0;
            while(size--){
                TreeNode* curr=que.front();
                que.pop();
                curr->val=currSum-curr->val;

                int sibSum=0;
                if(curr->left) {
                    que.push(curr->left);
                    nextSum+=curr->left->val;
                    sibSum+=curr->left->val;
                }
                if(curr->right) {
                    que.push(curr->right);
                    nextSum+=curr->right->val;
                    sibSum+=curr->right->val;
                }
                if(curr->left) curr->left->val=sibSum;
                if(curr->right) curr->right->val=sibSum;
            }
            currSum=nextSum;
        }
        if(root) root->val=0;
        return root;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        // return solution1(root); //O(N^2) time TLE space O(2N)

        // return solution2(root); // O(N) three pass solution TLE
 
        // return solution3(root); // accepted   O(N) two pass solution 

        return solution4(root); // accepted   O(N) one pass solution 
    }
};
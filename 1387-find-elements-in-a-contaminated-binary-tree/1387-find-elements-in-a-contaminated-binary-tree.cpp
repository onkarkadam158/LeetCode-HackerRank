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
class FindElements {
public:

    unordered_map<int,int>mp;
    FindElements(TreeNode* root) {
        if(!root) return ;
        queue<pair<TreeNode*,int>>que;
        que.push({root,0});
        mp[0]++;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                auto front=que.front();
                que.pop();
                TreeNode* curr=front.first;
                int num= front.second;
                mp[num]++;
                if(curr->left) {
                    que.push({curr->left,num*2+1});
                }
                if(curr->right){
                    que.push({curr->right,num*2+2});
                }
            }
        }
    }
    
    bool find(int target) {
        return mp.find(target)!=mp.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
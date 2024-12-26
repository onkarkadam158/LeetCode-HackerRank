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
    int maxi(int a,int b)
    {
        if(a>b)
            return a;
        return b;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>result;
        queue<TreeNode*>que;
        if(root)
            que.push(root);
        while(!que.empty())
        {
            long long int max=INT_MIN;
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=que.front();
                que.pop();
                max=maxi(max,curr->val);
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            result.push_back(max);
        }
        return result;
    }
};
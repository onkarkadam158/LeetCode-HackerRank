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
    vector<int>v;
    vector<int> preorderTraversal(TreeNode* root) {
        //Recursive Approach
        /*
        if(root!=NULL)
        {
            v.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return v;
        */

        //Iterative Approach

        //Method 1

        /*
        stack<TreeNode*>st;
        TreeNode* curr=root;
        while(curr!=NULL || !st.empty())
        {
            while(curr)
            {
                v.push_back(curr->val);
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            curr=curr->right;
        }
        */

        //Method 2
        
        if(root==NULL)
            return v;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* curr=st.top();
            st.pop();
            v.push_back(curr->val);
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left); 
        }
        return v;
    }
};
/*

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

*/
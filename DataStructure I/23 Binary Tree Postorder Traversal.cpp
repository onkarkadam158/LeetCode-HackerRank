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
    vector<int> postorderTraversal(TreeNode* root) {
        //Recursive Approach
        /*
        if(root!=NULL)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            v.push_back(root->val);
        }
        return v;
        */
        //Iterative Approach
        if(root==NULL)
            return v;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* curr=st.top();
            st.pop();
            v.push_back(curr->val);
            if(curr->left)
                st.push(curr->left);
            if(curr->right)
                st.push(curr->right);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
/*

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/
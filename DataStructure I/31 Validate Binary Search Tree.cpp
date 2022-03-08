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
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return ;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool check(TreeNode* root)
    {
        inorder(root);
        for(int i=1;i<v.size();i++)
            if(v[i-1]>=v[i])
                return false;
        return true;
    }
    bool recursiveSolution(long long int min,TreeNode* root,long long int max)
    {
        if(!root)
            return true;
        if( root->val > min and root->val < max)
            return recursiveSolution(min,root->left,root->val) and recursiveSolution(root->val,root->right,max);
        return false;
    }
    bool isValidBST(TreeNode* root) {
        //Naive Approach by finding inorder Traversal
        //return check(root);
        
        //By using recursion
        return  recursiveSolution(LLONG_MIN,root,LLONG_MAX);
    }
};
/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

*/
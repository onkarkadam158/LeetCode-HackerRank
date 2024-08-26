/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>result1;
    void recursiveSolution(Node* root)
    {
        if(!root)
            return ;
        int size=root->children.size();
        for(int i=0;i<size;i++)
        {
            if(root->children[i])
                recursiveSolution(root->children[i]);
        }
        result1.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        //recursiveSolution(root);
        //return result1;
        vector<int>result;
        if(!root)
            return result;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            Node* curr=st.top();
            st.pop();
            int size=curr->children.size();
            for(int i=0;i<size;i++){
                if(curr->children[i])
                    st.push(curr->children[i]);
            }
            result.push_back(curr->val);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};














class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string res="";
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(res.size());
            }
            else if(s[i]==')'){
                int top=st.top();
                reverse(res.begin()+top,res.end());
                st.pop();
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};
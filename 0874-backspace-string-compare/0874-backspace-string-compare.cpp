class Solution {
public:
    bool  isEqual(stack<char>&st1,stack<char>&st2){
        if(st1.size()!=st2.size()) return false;
        while(!st1.empty()){
            if(st1.top()!=st2.top()) return false;
            st1.pop(),st2.pop();
        }
        return true;
    }
    void doOperation(stack<char>&st,string&s){
        for(auto a:s){
            if(a!='#') {
                st.push(a);
            }
            else {
                if(!st.empty()){
                    st.pop();
                }
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        stack<char>st1,st2;
        doOperation(st1,s);
        doOperation(st2,t);
        return isEqual(st1,st2);
    }
};
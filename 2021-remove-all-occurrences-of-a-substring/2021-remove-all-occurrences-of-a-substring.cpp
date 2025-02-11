class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char>st;
        int n=s.size(),m=part.size();
        for(auto a:s){
            st.push(a);
            int i=m-1;
            stack<char>st1;
            while(st.size() and i>=0 and st.top()==part[i]){
                st1.push(part[i]);
                st.pop();    
                i--;
            }
            if(i!=-1){
                while(!st1.empty()){
                    st.push(st1.top());
                    st1.pop();
                }
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
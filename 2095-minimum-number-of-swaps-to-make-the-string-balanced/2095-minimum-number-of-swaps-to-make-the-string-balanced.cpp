class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto a:s){
            if(a=='['){
                st.push(a);
            }
            else{
                if(!st.empty()) st.pop();
            }
        }
        return int(st.size()+1)/2;
    }
};
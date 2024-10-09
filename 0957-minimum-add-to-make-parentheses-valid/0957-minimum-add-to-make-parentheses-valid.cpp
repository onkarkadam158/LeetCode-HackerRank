class Solution {
public:
    int stackSolution(string&s){
        stack<char>st;
        int close=0;
        for(auto a:s){
            if(a=='('){
                st.push(a);
            }
            else{
                if(!st.empty()) st.pop();
                else close++;
            }
        }
        return close+st.size();
    }
    int optimal(string&s){
        int size=0;
        int close=0;
        for(auto a:s){
            if(a=='('){
                size++;
            }
            else{
                if(size>0) size--;
                else close++;
            }
        }
        return close+size;
    }
    int minAddToMakeValid(string s) {
        // return stackSolution(s);
        return optimal(s);
    }
};
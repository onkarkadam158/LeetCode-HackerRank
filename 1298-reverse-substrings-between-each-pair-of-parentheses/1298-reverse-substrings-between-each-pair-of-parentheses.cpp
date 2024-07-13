class Solution {
public:
    string stackSolution(string &s){
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
    string twoPointerSolution(string &s){
        int n=s.size(),dirRtoL=1;
        string result="";
        unordered_map<int,int>mp1,mp2;
        int i=0,j=n-1;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    int top=st.top();
                    mp1[top]=i;
                    mp2[i]=top;
                    st.pop();
                }
            }
        }
        for(auto a:mp1)cout<<a.first<<" "<<a.second<<endl;
        i=0;
        while(i<n and i>=0){
            if(s[i]=='('){
                i=mp1[i];
                if(dirRtoL){
                    i--;
                    while(i>=0 and s[i]!='(' and s[i]!=')'){
                        result+=s[i--];
                    }
                }
                else{
                    i++;
                    while(i<n and s[i]!='(' and s[i]!=')'){
                        result+=s[i++];
                    }
                }
                dirRtoL=!dirRtoL;
            }
            else if(s[i]==')'){
                i=mp2[i];
                if(dirRtoL){
                    i--;
                    while(i>=0 and s[i]!='(' and s[i]!=')'){
                        result+=s[i--];
                    }
                }
                else{
                    i++;
                    while(i<n and s[i]!='(' and s[i]!=')'){
                        result+=s[i++];
                    }
                }
                dirRtoL=!dirRtoL;
            }
            else{
                result+=s[i++];
            }
        }
        return result;
    }
    string reverseParentheses(string s) {
        // return stackSolution(s); // O(n^2) time space O(n)
        return twoPointerSolution(s); //O(n) time and space O(n)
    }
};
class Solution {
public:
    int helper(string& str,char a,char b,int x){
        int n=str.size(),sum=0;
        stack<char>st;
        for(auto ch:str){
            if(ch==b){
                if(!st.empty() and st.top()==a){
                    sum+=x;
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
            else{
                st.push(ch);
            }
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        str=temp;
        
        return sum;
    }
    int maximumGain(string s, int x, int y) {
        int count=0;
        if(x>y){
            count+=helper(s,'a','b',x);
            count+=helper(s,'b','a',y);
        }
        else{
            count+=helper(s,'b','a',y);
            cout<<s<<" ";
            count+=helper(s,'a','b',x);
        }
        return count;
    }
};
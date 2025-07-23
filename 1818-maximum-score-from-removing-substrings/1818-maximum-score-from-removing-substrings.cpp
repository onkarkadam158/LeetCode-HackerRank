class Solution {
public:
    int remove_ab(string &s ,int x){
        stack<char>st;
        int count=0;
        for(auto curr:s){
            if(!st.empty()){
                if(st.top()=='a' and curr=='b'){
                    st.pop();
                    count+=x;
                    continue;
                }
            }
            st.push(curr);
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        s=temp;
        return count;
    }
    int remove_ba(string &s ,int y){
        stack<char>st;
        int count=0;
        for(auto curr:s){
            if(!st.empty()){
                if(st.top()=='b' and curr=='a'){
                    st.pop();
                    count+=y;
                    continue;
                }
            }
            st.push(curr);
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        s=temp;
        return count;
    }
    int maximumGain(string s, int x, int y) {
        int result=0;
        if(x>y){
            result+=remove_ab(s,x);
            result+=remove_ba(s,y);
        }
        else{
            result+=remove_ba(s,y);
            result+=remove_ab(s,x);
        }
        return result;
    }
};
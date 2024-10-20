class Solution {
public:
    char negation(vector<char>&temp){
        return temp[0]=='t' ? 'f' : 't';
    }
    char add(vector<char>&temp){
        for(auto a:temp){
            if(a=='f') return 'f';
        }
        return 't';
    }
    char oring(vector<char>&temp){
        for(auto a:temp){
            if(a=='t') return 't';
        }
        return 'f';
    }
    char evaluate(char op,vector<char>&temp){
        if(op=='!'){
            return negation(temp);
        }
        else if (op=='&'){
            return add(temp);
        }
        return oring(temp);
    }
    bool parseBoolExpr(string exp) {
        stack<char>st;
        int n=exp.size();
        for(int i=0;i<n;i++){
            if(exp[i]==',') continue;

            if(exp[i]==')'){
                vector<char>temp;
                while(!st.empty() and st.top()!='(' ){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(evaluate(op,temp));
            }
            else{
                st.push(exp[i]);
            }
        }
        return st.top()=='t' ? true : false; 
    }
};
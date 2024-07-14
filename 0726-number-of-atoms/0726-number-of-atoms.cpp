class Solution {
public:
    bool isCapital(char c){
        return c>='A' and c<='Z';
    }
    bool isSmall(char c){
        return c>='a' and c<='z';
    }
    bool isNumber(char c){
        return c>='0' and c<='9';
    }
    string countOfAtoms(string formula) {
        stack<unordered_map<string,int>>st;
        int n=formula.size(),i=0;
        unordered_map<string,int>stackMP;
        st.push(stackMP);
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>{});
                i++;
            }
            else if(formula[i]==')'){
                auto topMap=st.top();
                st.pop();
                i++;
                // get the number after closing bracket this is to multiply the stack
                string num="";
                while(isNumber(formula[i])){
                    num+=formula[i++];
                }
                if(num.size()==0) num="1";
                int mul=stoi(num);
                for(auto a:topMap){
                    topMap[a.first]*=mul;
                }
                //merging two maps
                for(auto a:topMap){
                    st.top()[a.first]+=a.second;
                }
            }
            else if(isCapital(formula[i])){
                string ele="";
                ele+=formula[i++];
                while(isSmall(formula[i])){
                    ele+=formula[i++];
                }
                string num="";
                while(isNumber(formula[i])){
                    num+=formula[i++];
                }
                if(num.size()==0) num="1";
                cout<<ele<<" "<<num<<endl;
                auto topMap=st.top();
                st.pop();
                topMap[ele]+=stoi(num);
                st.push(topMap);
            }
        }
        
        //generating result
        map<string,int>mp;
        while(!st.empty()){
            auto top=st.top();
            st.pop();
            for(auto a:top){
                mp[a.first]=a.second;
            }
        }
        string result="";
        for(auto a:mp){
            result+=a.first;
            if(a.second>1)
                result+=to_string(a.second);
        }
        return result;
    }
};
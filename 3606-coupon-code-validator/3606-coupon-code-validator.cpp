class Solution {
public:
    bool check1(string& str){
        if(str.size()==0) return false;
        for(auto s:str){
            if(s>='a' and s<='z'){
                continue;
            }
            else if(s>='A' and s<='Z'){
                continue;
            }
            else if(s>='0' and s<='9'){
                continue;
            }
            else if(s=='_'){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool check2(string& str){
        return str=="electronics" or str=="grocery" or str=="pharmacy" or str=="restaurant" ;
    }
    bool isValid(string& str1,string& str2){
        
        return check1(str1) and check2(str2);
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        int n=code.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            if(isActive[i]){
                if(isValid(code[i],businessLine[i])){
                    mp[businessLine[i]].push_back(code[i]);
                }
            }
        }
        for(auto &a:mp){
            sort(a.second.begin(),a.second.end());
        }
        vector<string> result;
        for(auto vec:mp["electronics"]){
            result.push_back(vec);
        }
        for(auto vec:mp["grocery"]){
            result.push_back(vec);    
        }
        for(auto vec:mp["pharmacy"]){
            result.push_back(vec);
        }
        for(auto vec:mp["restaurant"]){
            result.push_back(vec);
        }
        return result;
    }
};
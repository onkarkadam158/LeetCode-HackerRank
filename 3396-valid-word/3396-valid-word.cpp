class Solution {
public:
    bool isvowel(char c){
        vector<char>arr={'a','e','i','o','u','A','E','I','O','U'};
        for(auto a:arr){
            if(c==a) return true;
        }
        return false;
    }
    bool isdigit(char c){
        return c>='0' and c<='9';
    }
    bool ischar(char c){
        return (c>='a' and c<='z') or (c>='A' and c<='Z');
    }
    bool isconsonent(char c){
        if (isvowel(c)) return false;
        return ischar(c);
    }
    bool isValid(string w) {
        if(w.size()<3) return false;
        bool con=false,vow=false,dig=true;
        for(auto a:w){
            if(isvowel(a)){
                vow=true;
            }
            else if(isdigit(a)){
                dig=true;
            }
            else if(isconsonent(a)){
                con=true;
            }
            else {
                return false;
            }
        }
        return con and vow and dig;
    }
};
class Solution {
public:
    bool solve(int ind,int num,string& s,vector<string>&res){
        if(ind>=s.size()){
            int sum=0;
            for(auto a:res) sum+=stoi(a);
            return sum==num;
        }
        string temp="";
        for(int i=ind;i<s.size();i++ ){
            temp+=s[i];
            res.push_back(temp);
            if(solve(i+1,num,s,res)) return true;
            res.pop_back();
        }
        return false;
    }
    int punishmentNumber(int n) {
        int result=0;
        for(int i=1;i<=n;i++){
            int num=i*i;
            string s=to_string(num);
            vector<string> res;
            if(solve(0,i,s,res)){
                result+=(num);
                // cout<<num<<" ";
            }
        }
        return result;
    }
};
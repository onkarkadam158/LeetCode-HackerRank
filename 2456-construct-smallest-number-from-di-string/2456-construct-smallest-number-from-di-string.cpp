class Solution {
public:
    int n;
    bool solve(int ind,string& pattern,string temp,string& result, unordered_map<char,int>&mp){
        if(temp.size()==(n+1)){
            for(int i=0;i<n;i++){
                if(pattern[i]=='I'){
                    if(temp[i] >= temp[i+1]) return false;
                }
                else{
                    if(temp[i] <= temp[i+1]) return false;
                }
            }
            result=temp;
            return true;
        }
        temp+='0';
        for(int i=1;i<=9;i++){
            char num=('0'+i);
            if(mp.find(num)==mp.end()){
                temp[ind]=num;
                mp[num]++;
                if(solve(ind+1,pattern,temp,result,mp)) return true;
                temp[ind]='0';
                mp.erase(num);
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        n=pattern.size();
        string temp="",result="";
        unordered_map<char,int>mp;
        solve(0,pattern,temp,result,mp);
        return result;
    }
};
class Solution {
public:
    bool solve(int ind,int n,vector<int>&res,unordered_map<int,int>&mp,vector<int>&result){
        if(mp.size()==(n) or ind>=res.size()){
            result=res;
            return true;
        }
        if(res[ind]!=-1) {
            if(solve(ind+1,n,res,mp,result)) return true;
        }
        for(int num=n;num>=1;num--){
            if(mp.find(num)==mp.end() and res[ind]==-1){
                mp[num]++;
                res[ind]=num;
                if(num!=1){
                    if((ind+num)<res.size() and res[ind+num]==-1){
                        res[ind+num]=num;
                        if(solve(ind+1,n,res,mp,result)) return true;
                        res[ind+num]=-1;
                    }
                }
                else{
                    if(solve(ind+1,n,res,mp,result)) return true;
                }
                res[ind]=-1;
                mp.erase(num);
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(2*(n-1)+1,-1),result;
        unordered_map<int,int>mp;
        solve(0,n,res,mp,result);
        return result;
    }
};
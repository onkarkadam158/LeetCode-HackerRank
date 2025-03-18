class Solution {
public:
    int max(int a,unsigned long b){
        if(a>b) return a;
        return b;
    }
    int bruteforce(vector<int>& nums){
        int res=1,n=nums.size();
        vector<vector<int>>subarr;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=i;j<n;j++){
                temp.push_back(nums[j]);
                subarr.push_back(temp);
            }
        }
        for(int k=0;k<subarr.size();k++){
            bool t=true;
            for(int i=0;i<subarr[k].size();i++){
                for(int j=i+1;j<subarr[k].size();j++){
                    if((subarr[k][i]&subarr[k][j])!=0){
                        t=false;
                    }
                }
            }
            if(t){
                res=max(res,subarr[k].size());
            }
        }
        return res;
    }
    bool check(vector<int>&mp){
        for(auto a:mp){
            if(a>1) return false;
        }
        return true;
    }
    void add(int n,vector<int>&mp){
        int i=0;
        while(n){
            if(n%2)mp[i]++;
            i++;
            n=n/2;
        }
    }
    void remove(int n,vector<int>&mp){
        int i=0;
        while(n){
            if(n%2)mp[i]--;
            i++;
            n=n/2;
        }
    }
    int longestNiceSubarray(vector<int>& nums) {
        //return bruteforce(nums);
        int res=1,n=nums.size();
        vector<int>mp(32,0);
        for(int i=0,j=0;i<n,j<n;j++){
            add(nums[j],mp);
            if(check(mp)){
                res=max(res,j-i+1);
            }
            else{
                while(i<j and !check(mp)){
                    remove(nums[i],mp);
                    i++;
                }
                if(check(mp)){
                    res=max(res,j-i+1);
                }   
            }
        }
        return res;
    }
};































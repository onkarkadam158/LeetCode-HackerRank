class Solution {
public:
    vector<string>getTokens(string& expression){
        vector<string>temp;
        string t="";
        for(auto a:expression){
            if(a>='0' and a<='9'){
                t+=a;
            }
            else{
                temp.push_back(t);
                string x="";
                x+=a;
                temp.push_back(x);
                t="";
            }
        }
        temp.push_back(t);
        // for(auto a:temp) cout<<a<<" ";
        return temp;
    }
    vector<int> solve(int i,int j,vector<string>&arr){
        if(i>=j) return {stoi(arr[i])};
        vector<int>res;
        for(int ind=i;ind<=j;ind++){
            if(arr[ind]=="+" or arr[ind]=="-" or arr[ind]=="*"){
                vector<int>a=solve(i,ind-1,arr);
                vector<int>b=solve(ind+1,j,arr);
                for(auto x:a){
                    for(auto y:b){
                        if(arr[ind]=="+") res.push_back(x+y);
                        if(arr[ind]=="*") res.push_back(x*y);
                        if(arr[ind]=="-") res.push_back(x-y);
                    }
                }
            }
        }
        return res;
    }
    vector<int> memoization(int i,int j,vector<string>&arr,vector<vector<vector<int>>>&dp){
        if(i>=j) return {stoi(arr[i])};
        if(dp[i][j].size()!=0) return dp[i][j];
        vector<int>res;
        for(int ind=i;ind<=j;ind++){
            if(arr[ind]=="+" or arr[ind]=="-" or arr[ind]=="*"){
                vector<int>a=memoization(i,ind-1,arr,dp);
                vector<int>b=memoization(ind+1,j,arr,dp);
                for(auto x:a){
                    for(auto y:b){
                        if(arr[ind]=="+") res.push_back(x+y);
                        if(arr[ind]=="*") res.push_back(x*y);
                        if(arr[ind]=="-") res.push_back(x-y);
                    }
                }
            }
        }
        return dp[i][j]=res;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<string>arr=getTokens(expression);
        int n=arr.size();
        // for(auto a:arr)cout<<a<<" ";

        //bruteforce
        // return solve(0,n-1,arr);
    
        //memoization
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1));
        return memoization(0,n-1,arr,dp);

    }
};
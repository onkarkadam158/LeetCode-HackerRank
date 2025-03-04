class Solution {
public:
    vector<int>arr;
    bool bruteforce(int ind,int n,int num){
        if(num<0) return false;
        if(num==0) return true;
        if(ind>=n) return false;

        int take=bruteforce(ind+1,n,num-arr[ind]);
        int ntake=bruteforce(ind+1,n,num);

        return take or ntake;
    }
    bool memoization(int ind,int n,int num,vector<vector<int>>dp){
        if(num<0) return false;
        if(num==0) return true;
        if(ind>=n) return false;

        if(dp[ind][num]!=-1) return dp[ind][num];

        int take=memoization(ind+1,n,num-arr[ind],dp);
        int ntake=memoization(ind+1,n,num,dp);

        return dp[ind][num]=(take or ntake);
    }
    bool mathSolution(int num){
        while(num){
            if(num%3==2) return false;
            num=num/3;
        }
        return true;
    }
    bool checkPowersOfThree(int n) {
        arr.clear();
        for(int i=0;i<18;i++){
            arr.push_back(pow(3,i));
        }

        //recursive bruteforce solution
        // return bruteforce(0,18,n);

        //recursive memoization solution
        // vector<vector<int>>dp(18,vector<int>(1e7+1,-1));
        // return memoization(0,18,n,dp);

        return mathSolution(n);

    }
};
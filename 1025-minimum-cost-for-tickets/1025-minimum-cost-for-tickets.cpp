class Solution {
public:
    //Recursive bruteforce solution 
    int bruteforce(int ind,int day,vector<int>&days,vector<int>&costs){
        if(ind>=days.size()) return 0;
        
        if(days[ind]<=day) return bruteforce(ind+1,day,days,costs);

        int day1=costs[0]+bruteforce(ind+1,days[ind],days,costs);
        int day7=costs[1]+bruteforce(ind+1,days[ind]+6,days,costs);
        int day30=costs[2]+bruteforce(ind+1,days[ind]+29,days,costs);

        return min(day1,min(day7,day30));
    }
    
    //Recursive memoization solution 
    int memoization(int ind,int day,vector<int>&days,vector<int>&costs,vector<vector<int>>&dp){
        if(ind>=days.size()) return 0;
        
        if(dp[ind][day]!=-1) return dp[ind][day];

        if(days[ind]<=day) return memoization(ind+1,day,days,costs,dp);

        int day1=costs[0]+memoization(ind+1,days[ind],days,costs,dp);
        int day7=costs[1]+memoization(ind+1,days[ind]+6,days,costs,dp);
        int day30=costs[2]+memoization(ind+1,days[ind]+29,days,costs,dp);

        return dp[ind][day]=min(day1,min(day7,day30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return bruteforce(0,0,days,costs); //TLE
        
        vector<vector<int>>dp(366,vector<int>(366*2,-1));
        return memoization(0,0,days,costs,dp);
    }
};
class Solution {
public:
    bool isoverlapping(vector<int>&point1,vector<int>&point2){
        int x1=point1[0],y1=point1[1];
        int x2=point2[0],y2=point2[1];
        if(x1==x2) return true;
        else if(x1<x2){
            if(y1>=x2) return true;
        }
        else{
            if(y2>=x1) return true;
        }
        return false;
    }
    int solve(int ind,int prev, vector<vector<int>>& events,int n,int count){
        if(ind>=n) return 0;

        int ntake=solve(ind+1,prev,events,n,count);
        int take=0;
        if(prev==-1 ){
            take=events[ind][2]+solve(ind+1,ind,events,n,count+1);
        }
        else if(count<2 and !isoverlapping(events[prev],events[ind])){
            take=events[ind][2]+solve(ind+1,ind,events,n,count+1);    
        }
        return max(take,ntake);
    }
    int memoization(int ind,int prev, vector<vector<int>>& events,int n,int count,vector<vector<vector<int>>>&dp){
        if(ind>=n) return 0;
        if(dp[ind][prev+1][count]!=-1) return dp[ind][prev+1][count]; 
        int ntake=memoization(ind+1,prev,events,n,count,dp);
        int take=0;
        if(prev==-1 ){
            take=events[ind][2]+memoization(ind+1,ind,events,n,count+1,dp);
        }
        else if(count<2 and !isoverlapping(events[prev],events[ind])){
            take=events[ind][2]+memoization(ind+1,ind,events,n,count+1,dp);    
        }
        return dp[ind][prev+1][count]=max(take,ntake);
    } 
    
    int solution1(vector<vector<int>>& events){
        int res=0;
        
        for(int i=0;i<events.size();i++){   
            res=max(res,events[i][2]); 
            for(int j=0;j<events.size();j++){
                if(i!=j and !isoverlapping(events[i],events[j])){
                    res=max(res,events[i][2]+events[j][2]);
                }
            }
        }
        return res;
    }

    int binarySearch(int num,vector<vector<int>>&events){
        int low=0,high=events.size()-1;
        int ans=high+1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(events[mid][0] > num){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int optimalMemoization(int ind, vector<vector<int>>& events,int count,vector<vector<int>>&dp){
        if(ind>=events.size() or count>=2) return 0;
        
        if(dp[ind][count]!=-1) return dp[ind][count]; 
        int ntake=optimalMemoization(ind+1,events,count,dp);
           
        int i=binarySearch(events[ind][1],events);
        int take=events[ind][2]+optimalMemoization(i,events,count+1,dp);    
    
        return dp[ind][count]=max(take,ntake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();

        //Bruteforce recusrion exponential  time 
        // return solve(0,-1,events,n,0,);

        // memoization (N^2) time (N^2) space
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(3,-1)));
        // return memoization(0,-1,events,n,0,dp);


        // solution (N^2) time (1) space
        // return solution1(events);

        sort(events.begin(),events.end());
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return optimalMemoization(0,events,0,dp);
    }
};
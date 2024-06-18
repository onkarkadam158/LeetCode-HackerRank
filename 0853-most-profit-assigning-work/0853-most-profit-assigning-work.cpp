class Solution {
public:
    int n,m;
    int bruteforce(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxProfit=0;
        for(int i=0;i<m;i++){
            int tempMaxProfit=0;
            for(int j=0;j<n;j++){
                if(difficulty[j]<=worker[i]){
                    tempMaxProfit=max(tempMaxProfit,profit[j]);
                }
            }
            maxProfit+=tempMaxProfit;
        }
        return maxProfit;
    }
    int optimal(vector<int>& diff, vector<int>& prof, vector<int>& w) {
        int maxProfit=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
           mp[diff[i]]=max(mp[diff[i]],prof[i]);
        }
        sort(diff.begin(),diff.end());
        int maxProfitSoFar=0;
        for(int i=0;i<n;i++){
            maxProfitSoFar=max(maxProfitSoFar,mp[diff[i]]);
            mp[diff[i]]=maxProfitSoFar;
        }
        for(int i=0;i<m;i++){
            int ind=upper_bound(diff.begin(),diff.end(),w[i])-diff.begin()-1;
            if(ind>=0)maxProfit+=mp[diff[ind]];
        }
        return maxProfit;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        n=profit.size(),m=worker.size();
        // return bruteforce(difficulty,profit,worker);//time O(N^2) space O(1)
        return optimal(difficulty,profit,worker);//time O(mlogn) space O(n)
    }
};
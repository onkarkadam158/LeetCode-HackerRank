class Solution {
public:
    int getBallsForDist(vector<int>& pos, int dist,int n){
        int prev=pos[0],cnt=1;
        for(int i=1;i<n;i++){
            if((pos[i]-prev) >= dist){
                prev=pos[i];
                cnt++;
            }
        }
        return cnt;
    }
    int maxDistance(vector<int>& pos, int m) {
        int n=pos.size();
        sort(pos.begin(),pos.end());
        int ans=0,low=0,high=pos[n-1]-pos[0];
        while(low<=high){
            int mid=(low+high)/2;
            int balls=getBallsForDist(pos,mid,n);
            if(balls>=m){
                ans=max(ans,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};

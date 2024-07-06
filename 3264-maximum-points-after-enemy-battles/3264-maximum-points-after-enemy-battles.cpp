class Solution {
public:
    long long maximumPoints(vector<int>& arr, int curr) {
        long long ans=0,sum=0;
        int n=arr.size();
        vector<int>pref;
        sort(arr.begin(),arr.end());
        if(curr<arr[0]) return 0;
        for(int i=1;i<n;i++){
            sum+=arr[i]-arr[0];
        }
        ans+=n-1+((sum+curr)/(arr[0]));
        return ans;

        for(auto a:arr){
            if(curr>=a){
                curr-=a;
                ans++;
            }
            sum+=a;
            pref.push_back(sum);
        }
        

        if(ans==0) return 0;
        for(int i=n-1;i>=0;i--){
           curr+=arr[i];
           int ind=upper_bound(pref.begin(),pref.end(),curr)-pref.begin();
           curr-=pref[ind-1];
           cout<<ind<<" ";
           ind=min(i-1,ind-1);
           ans+=ind;
        }
        return ans;

        
    }
};
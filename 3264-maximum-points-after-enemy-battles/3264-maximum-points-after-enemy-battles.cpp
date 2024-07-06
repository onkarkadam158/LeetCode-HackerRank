class Solution {
public:
    long long maximumPoints(vector<int>& arr, int curr) {
        long long ans=0,sum=0;
        int n=arr.size();
        vector<int>pref;
        sort(arr.begin(),arr.end());
        if(curr<arr[0]) return 0;
        for(int i=1;i<n;i++){
            sum+=arr[i];
        }
        return (sum+curr)/arr[0];        
    }
};
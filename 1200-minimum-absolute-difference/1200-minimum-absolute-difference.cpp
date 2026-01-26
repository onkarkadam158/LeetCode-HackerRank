class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minDiff=INT_MAX;
        int n=arr.size();
        for(int i=1;i<n;i++){
            minDiff=min(minDiff,arr[i]-arr[i-1]);
        }
        vector<vector<int>>res;

        for(int i=1;i<n;i++){
            if(minDiff==(arr[i]-arr[i-1])){
                res.push_back({arr[i-1],arr[i]});
            }
        }
        return res;
    }
};
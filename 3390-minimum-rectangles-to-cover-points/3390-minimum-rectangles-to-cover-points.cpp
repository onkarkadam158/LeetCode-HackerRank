class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        map<int,int>mp;
        for(auto &a:points)mp[a[0]]++;
        vector<int>arr;
        for(auto a:mp)arr.push_back(a.first);
        int count=0,n=arr.size();
        for(int i=0;i<n;){
            int ind=upper_bound(arr.begin(),arr.end(),arr[i]+w)-arr.begin();
            i=ind;
            count++;
        }
        
        return count;
    }
};
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto a:arr1)mp[a]++;
        vector<int>res;
        for(auto a:arr2){
            int count=mp[a];
            while(count--)res.push_back(a);
            mp[a]=0;
        }
        for(auto &a:mp){
            int count=a.second;
            while(count--)res.push_back(a.first);
            a.second=0;
        }
        return res;
    }
};
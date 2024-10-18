class Solution {
public:
    #define pii pair<int,int>
    vector<int>solution1(vector<int>& nums, int k){
        map<int,int>mp;
        for(auto a:nums){
           mp[a]++;
        }
        map<int,vector<int>>mp2;
        for(auto a:mp){
            mp2[a.second].push_back(a.first);
        }
        vector<int>res;
        vector<int>temp;
        for(auto a:mp2){
            vector<int>t=a.second;
            for(int i=0;i<t.size();i++){
                temp.push_back(t[i]);
            }
        }
        for(int i=0;i<k;i++){
            res.push_back(temp[temp.size()-1-i]);
        }
        return res;
    }
    vector<int> solution2(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        for(auto a:nums) mp[a]++;
        priority_queue<pii>pq;
        for(auto a:mp){
            pq.push({a.second,a.first});
        }
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    vector<int> solution3(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(auto a:nums){
            mp[a]++;
        }
        for(auto a:mp){
            pq.push({a.second,a.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // return solution1(nums,k);

        // return solution2(nums,k); // time O(Nlogn) space O(N) 

        return solution3(nums,k);
    }
};
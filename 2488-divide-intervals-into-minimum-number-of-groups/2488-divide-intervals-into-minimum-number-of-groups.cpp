class Solution {
public:
    int bruteforce(vector<vector<int>>& intervals){
        vector<int>mp;
        sort(intervals.begin(),intervals.end());
        for(auto interval:intervals){
            int start=interval[0],end=interval[1];
            bool overlapped=0;
            for(auto &x:mp){
                if(start>x){
                    x=start;
                    overlapped=1;
                    break;
                }
            }
            if(!overlapped) mp.push_back(end);
            sort(mp.rbegin(),mp.rend());
        }
        return mp.size();
    }
    int optimal(vector<vector<int>>& intervals){
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto interval:intervals){
            int start=interval[0],end=interval[1];
            if(!pq.empty() and start>pq.top()){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
    int minGroups(vector<vector<int>>& intervals) {
        // return bruteforce(intervals);
        return optimal(intervals);
    }
};
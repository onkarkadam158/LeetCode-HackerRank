class Solution {
public:
    #define pii pair<int,int>
    #define ppii pair<int,pair<int,int>>
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        priority_queue<ppii,vector<ppii>,greater<ppii>>pq;
        set<pii>st;
        
        pq.push({nums1[0]+nums2[0],{0,0}});
        st.insert({0,0});
        vector<vector<int>>res;
        while(k--){
            auto top=pq.top();
            pq.pop();
            int x=top.second.first,y=top.second.second;
            res.push_back({nums1[x],nums2[y]});
            if(x+1<n and st.find({x+1,y})==st.end() ){
                pq.push({nums1[x+1]+nums2[y],{x+1,y}});
                st.insert({x+1,y});
            }
            if(y+1<m and st.find({x,y+1})==st.end() ){
                pq.push({nums1[x]+nums2[y+1],{x,y+1}});
                st.insert({x,y+1});
            }
        }
        return res;

    }
};
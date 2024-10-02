class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        set<int>st;
        for(auto a:arr)
            st.insert(a);
        int rank=1;
        for(auto a:st)
            mp[a]=rank++;
        for(int i=0;i<arr.size();i++)
            arr[i]=(mp[arr[i]]);   
        
        return arr;
    }
};
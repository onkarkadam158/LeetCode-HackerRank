class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if((n%groupSize)!=0) return false;
        map<int,int>mp;
        for(auto a:hand)mp[a]++;
        while(mp.size()>0){
            int k=groupSize-1;
            int num=mp.begin()->first;
            cout<<num<<" ";
            mp[num]--;
            if(mp[num]==0) mp.erase(num);
            while(k--){
                num++;
                if(mp.find(num)==mp.end()) return false;                
                mp[num]--;
                if(mp[num]==0) mp.erase(num);
            }
        }
        return true;
    }
};
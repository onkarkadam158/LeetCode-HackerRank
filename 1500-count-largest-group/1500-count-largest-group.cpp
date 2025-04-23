class Solution {
public:
    int digisum(int d){
        int sum=0;
        while(d){
            sum+=d%10;
            d=d/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        map<int,vector<int>>mp;
        for(int i=1;i<=n;i++){
            int sum=digisum(i);
            mp[sum].push_back(i);
        }
        int count=0,max=0;
        for(auto a:mp){
            if(a.second.size()>max)
                max=a.second.size();
        }
        for(auto a:mp){
            if(a.second.size()==max)
                count++;
        }
        return count;
    }
};
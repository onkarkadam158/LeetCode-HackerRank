class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
        int n=cus.size();
        long long res=cus[0][1];
        long long end=res+cus[0][0];
        for(int i=1;i<n;i++){
            int arrival=cus[i][0],time=cus[i][1];
            if(end<arrival){
                res+=time;
                end=arrival+time;
            }
            else{
                res+=end+time-arrival;
                end=end+time;
            }
        }
        return double(res)/n;
    }
};
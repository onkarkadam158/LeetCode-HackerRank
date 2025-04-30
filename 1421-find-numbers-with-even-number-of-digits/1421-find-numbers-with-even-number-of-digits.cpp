class Solution {
public:
    bool iseven(int a){
        int cnt=0;
        while(a){
            cnt++;
            a/=10;
        }
        return cnt%2==0;
    }
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(auto a:nums){
            if(iseven(a)){
                cnt++;
            }
        }
        return cnt;
    }
};
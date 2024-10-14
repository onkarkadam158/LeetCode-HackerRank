class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>que;
        for(auto a:nums){
            que.push(a);
        }
        long long res=0;
        while(k--){
            int t=que.top();
            que.pop();
            res+=t;
            que.push(ceil(double(t)/3));
        }
        return res;
    }
};
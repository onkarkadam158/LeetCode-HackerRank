class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto a:nums) pq.push(a);
        while(pq.size()>1 ){
            long long first=pq.top();
            if(first>=k) break;
            pq.pop();
            long long second=pq.top();
            pq.pop();
            count++;
            pq.push(2*min(first,second) + max(first,second));
        }
        return count;
    }
};
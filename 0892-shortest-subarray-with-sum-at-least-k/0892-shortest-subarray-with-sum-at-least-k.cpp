class Solution {
public:
    
    int bruteforce(vector<int>& nums, int k) {
        int n=nums.size();
        int res=n+1;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum>=k){
                    res=min(res,j-i+1);
                }
            }
        }
        return res==(n+1) ? -1 : res;
    }
    int optimal(vector<int>& nums, int k) { 
        int n=nums.size();
        int res=n+1;
        deque<int>dq;
        vector<long long>pref(n,0);
        int j=0;
        while(j<n){
            if(j==0){ 
                pref[j]+=nums[j];
            }
            else{
                pref[j]+=pref[j-1]+nums[j];
            }

            if(pref[j]>=k){
                res=min(res,j+1);
            }

            while(!dq.empty() and pref[j]-pref[dq.front()]>=k){
                res=min(res,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() and pref[j]<= pref[dq.back()] ){
                dq.pop_back();
            }

            dq.push_back(j);
            j++;
        }
       
       
        return res==(n+1) ? -1 : res;
    }
    int shortestSubarray(vector<int>& nums, int k) {
        // return bruteforce(nums,k); // O(N^2) time and O(1) space 
        return optimal(nums,k); // O(2N) time and O(1) space
    }
};
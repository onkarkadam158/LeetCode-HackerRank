class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    //solution 1
    ll getMin(vector<int>& nums, vector<int>& cost,int num){
        ll res=0;
        for(int i=0;i<nums.size();i++){
            ll c=cost[i];
            ll diff=abs(num-nums[i]);
            res+=(c*diff);
        }

        return res;
    }
    long long brute(vector<int>& nums, vector<int>& cost){
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        long long ans=LLONG_MAX;
        for(int num=mini;num<=maxi;num++){
            ll temp=getMin(nums,cost,num);
            ans=min(ans,temp);
        }

        return ans;

    }
    long long binarySearch(vector<int>& nums, vector<int>& cost){
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());

        long long ans=LLONG_MAX;
        while(low<=high){
            ll mid=low+(-low+high)/2;
            ll temp1=getMin(nums,cost,mid);
            ll temp2=getMin(nums,cost,mid+1);
            ans = min(temp1,temp2);
            if(temp1>=temp2 ){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;

    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // return brute(nums,cost);   

        return binarySearch(nums,cost);
    }
};
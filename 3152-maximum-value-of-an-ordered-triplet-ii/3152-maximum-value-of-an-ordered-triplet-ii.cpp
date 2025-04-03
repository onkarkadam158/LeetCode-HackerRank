class Solution {
public:
    #define ll long long
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<ll>nextGreater(n,0);
        vector<ll>prevGreater(n,0);
        int greater=nums[n-1];
        for(int i=n-1;i>=0;i--){
            nextGreater[i]=greater;
            greater=max(greater,nums[i]);
        }
        greater=nums[0];
        for(int i=0;i<n;i++){
            prevGreater[i]=greater;
            greater=max(greater,nums[i]);
        }
        // for(auto a:prevGreater) cout<<a<<" ";
        // cout<<endl;
        // for(auto a:nums) cout<<a<<" ";
        // cout<<endl;
        // for(auto a:nextGreater) cout<<a<<" ";
        
        
        ll res=-1e6;

        for(int j=1;j<n-1;j++){
            ll temp =(prevGreater[j]-nums[j])*nextGreater[j];
            res=max(res,temp);
        }

        return max( (ll) 0 , res);
    }
};
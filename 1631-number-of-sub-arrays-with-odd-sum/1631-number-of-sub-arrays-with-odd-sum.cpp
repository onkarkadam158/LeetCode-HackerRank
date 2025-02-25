class Solution {
public:
    int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        long long res=0,sum=0;;
        long long evenSumCount=0,oddSumCount=0;
        for(int i=0;i<n;i++){
            sum+=(arr[i]%2);
            if(sum%2){
                res=(res+evenSumCount+1)%mod;
                oddSumCount++;
            }
            else{
                res=(res+oddSumCount)%mod;
                evenSumCount++;
            }
        }
        return res%mod;
    }
};
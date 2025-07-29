class Solution {
public:
    vector<int> bruteforce(vector<int>& nums,int n){
        vector<int>maxOr(n),result(n);
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=i;j<n;j++){
                temp=temp|nums[j];
            }
            maxOr[i]=temp;
        }
        for(int i=0;i<n;i++){
            int temp=0,j=i;
            for( j=i;j<n;j++){
                temp=temp|nums[j];
                if(temp==maxOr[i]){
                    break;
                }
            }
            result[i]=(j-i+1);
        }
        return result;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        // return bruteforce(nums,n);
        vector<int>result(n),maxOr(n),nextBit(32,n-1);
        int temp=0;
        for(int i=n-1;i>=0;i--){
            temp=temp|nums[i];
            maxOr[i]=temp;
        }
        for(auto a:maxOr) cout<<a<<" ";
        for(int i=n-1;i>=0;i--){
            int neededOr = maxOr[i];
            int ind=0,maxJ=i;
            int currNum=nums[i];
            while(neededOr){
                if(neededOr%2 and currNum%2==0){
                    maxJ=max(maxJ,nextBit[ind]);
                }
                neededOr/=2;
                currNum/=2;
                ind++;
            }
            result[i]=(maxJ-i+1);
            currNum=nums[i];
            ind=0;
            while(currNum){
                if(currNum%2){
                    nextBit[ind]=i;
                }
                currNum/=2;
                ind++;
            }
        }
        return result;
    }
};
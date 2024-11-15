class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int I=0,J=n-1;
        while(J>0 and arr[J-1]<=arr[J]) J--;
        while(I<n-1 and arr[I]<=arr[I+1]) I++;
        
        if(J==0) return 0;
        cout<<I<<" "<<J<<"\n";
        int res=n-1;
        res=min(n-1,min(J,n-(I+1)));
        int i=0,j=J;
        while(i<=I and j<n){
            if(arr[i]<=arr[j]){
                res=min(res,j-i-1);
                i++;
            }
            else j++;
        }
        return res;
    }
};
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            arr[i]=i+1;
        int a=0;
        for(int i=0;i<n-1;i++){
            a=(a+k-1)%(arr.size());
            arr.erase(arr.begin()+a);
            
        }
        return arr[0];
    }
};
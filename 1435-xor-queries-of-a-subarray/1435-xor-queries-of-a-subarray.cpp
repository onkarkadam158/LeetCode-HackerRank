class Solution {
public:
    vector<int> bruteforce(vector<int>& arr, vector<vector<int>>& queries){
        vector<int>res;
        for(auto a:queries){
            int left=a[0],right=a[1];
            int temp=0;
            for(int i=left;i<=right;i++){
                temp=temp^arr[i];
            }
            res.push_back(temp);
        }
        return res;
    }
    vector<int> optimal(vector<int>& arr, vector<vector<int>>& queries){
        int n=arr.size();
        vector<int>result,pref(n+1);
        pref[0]=arr[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]^arr[i];
        }
        for(auto a:queries){
            int left=a[0],right=a[1];
            int temp=pref[right];
            if(left-1>=0) temp=temp^pref[left-1];
            result.push_back(temp);
        }
        return result;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // return bruteforce(arr,queries);

        return optimal(arr,queries);
    }
};
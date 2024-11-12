class Solution {
public:
    vector<int> bruteforce(vector<vector<int>>& items, vector<int>& queries){
        int n=queries.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int maxBeauty=0;
            int price=queries[i];
            for(auto a:items){
                if(a[0]<=price)
                    maxBeauty=max(maxBeauty,a[1]);
            }
            res[i]=maxBeauty;
        }
        return res;
    }
    int getIndex(vector<vector<int>>& items,int price){
        int n=items.size();
        int low=0,high=n-1,maxBeauty=0;
        while(low<=high){
            int mid= low + (-low + high)/2;
            if(items[mid][0]<=price){
                maxBeauty=max(maxBeauty,items[mid][1]);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return maxBeauty;
    }
    vector<int> binarySearch(vector<vector<int>>& items, vector<int>& queries){
        int n=queries.size();
        sort(items.begin(),items.end());
        vector<int>res(n,0);

        int maxBeauty=0;
        for(int i=0;i<items.size();i++){
            maxBeauty=max(maxBeauty,items[i][1]);
            items[i][1]= maxBeauty;
        }
        for(int i=0;i<n;i++){
            res[i]= getIndex(items,queries[i]);
        }
        return res;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // return bruteforce(items,queries); (On^2) time space O(1)

        return binarySearch(items,queries);
    }
};
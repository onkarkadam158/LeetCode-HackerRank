class Solution {
public:
    bool possible(unordered_set<int>st,int n,int maxSum,int mid){
        int count=0,sum=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                if(sum+i<=maxSum){
                    sum+=i;
                    count++;
                }
            }
        }
        return count==mid;
    }
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st;
        for(auto a:banned) st.insert(a);
        int count=0,sum=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                if(sum+i<=maxSum){
                    sum+=i;
                    count++;
                }
            }
        }
        return count;
        int low=1,high=n-st.size(),res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(st,n,maxSum,mid)){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};
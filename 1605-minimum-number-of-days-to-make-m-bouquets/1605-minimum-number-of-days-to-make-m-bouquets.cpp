class Solution {
public:
    void getMaxiMini(vector<int>& bloomDay, int n,int &high,int& low){
        for(auto &a:bloomDay){
            high=max(high,a);
            low=min(low,a);
        }
    }
    bool possible(vector<int>& bloomDay, int m, int mid,int k){
        int count=0,cnt=0;
        for(auto &a:bloomDay){
            if(a<=mid){
                //bloomed
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt==k){
                count++;
                cnt=0;
            }
        }
        return count>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=1e9,high=-1e9,answer=-1;
        getMaxiMini(bloomDay,n,high,low);
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,m,mid,k)){
                answer=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return answer;
    }
};
class Solution {
public:
    long long getCarsDone(vector<int>& ranks,long long mid){
        long long count=0;
        for(int i=0;i<ranks.size();i++){
            count+=(int)sqrt((mid/ranks[i]));
        }
        return count;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans=0,low=0,high=1e18;
        while(low<=high){
            long long mid=(low+high)/2;
            long long carsDone=getCarsDone(ranks,mid);
            if(carsDone<cars){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
class Solution {
public:
    bool getProductsDistributed(vector<int>& quant,int n,int mid){
        int cnt=0;
        for(int i=0;i<quant.size();i++){
            cnt+=(quant[i]/mid);
            cnt+=(quant[i]%mid!=0);
        }
        return cnt<=n;
    }
    int minimizedMaximum(int n, vector<int>& quant) {
        int m=quant.size(),low=1,high=*max_element(quant.begin(),quant.end());
        int answer=high;
        while(low<=high){
            int mid=(low+high)/2;
            bool possible=getProductsDistributed(quant,n,mid);
            if(possible){
                answer=min(answer,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return answer;
    }
};
class Solution {
public:
    int get1 (vector<vector<int>>& arrays){
        int mini=1e4,maxi=-1e4;
        int n=arrays.size(),ind=0;
        for(int i=0;i<n;i++){
            int num=arrays[i][0];
            if(num<mini){
                mini=num;
                ind=i;
            }
        }
        for(int i=0;i<n;i++){
            int sz=arrays[i].size();
            int num=arrays[i][sz-1];
            if(num>maxi and i!=ind){
                maxi=num;
            }
        }
        return maxi-mini;
    }
    int get2 (vector<vector<int>>& arrays){
        int mini=1e4,maxi=-1e4;
        int n=arrays.size(),ind=0;
        for(int i=0;i<n;i++){
            int sz=arrays[i].size();
            int num=arrays[i][sz-1];
            if(num>maxi ){
                maxi=num;
                ind=i;
            }
        }
        for(int i=0;i<n;i++){
            int num=arrays[i][0];
            if(num<mini and i!=ind){
                mini=num;
            }
        }
        return maxi-mini;
    }
    int maxDistance(vector<vector<int>>& arrays) {

        return max(get1(arrays),get2(arrays));
    }
};
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long total=0;
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        long long h=0,v=0,hpiece=1,vpiece=1 ; 
        while(h<m-1 or v<n-1){
            if(h<m-1 and v<n-1){
                if(horizontalCut[h] > verticalCut[v]){
                    total+=horizontalCut[h]*vpiece;
                    h++;
                    hpiece++;
                }
                else{
                    total+=verticalCut[v]*hpiece;
                    v++;
                    vpiece++;
                }
            }
            else if(h<m-1){
                total+=horizontalCut[h]*vpiece;
                h++;
                hpiece++;
            }
            else{
                total+=verticalCut[v]*hpiece;
                v++;
                vpiece++;
            }
        }

        return total;
    }
};
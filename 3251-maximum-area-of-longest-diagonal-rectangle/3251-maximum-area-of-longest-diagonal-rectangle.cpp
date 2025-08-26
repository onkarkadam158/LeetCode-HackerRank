class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area=0;
        double dia=0;
        for(auto a:dimensions){
            int l=a[0],b=a[1];
            if((double(sqrt(l*l+b*b))) > dia){
                dia = double(sqrt(l*l+b*b));
            }
        }
        for(auto a:dimensions){
            int l=a[0],b=a[1];
            if((double(sqrt(l*l+b*b))) == dia){
                area=max(area,l*b);
            }
        }
        return area;
    }
};
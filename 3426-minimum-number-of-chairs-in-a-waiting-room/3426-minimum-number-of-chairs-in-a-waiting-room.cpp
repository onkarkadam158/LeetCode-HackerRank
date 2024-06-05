class Solution {
public:
    int minimumChairs(string s) {
        int e=0;
        int res=0;
        for(auto a:s){
            if(a=='E')e++;
            else e--;
            res=max(e,res);
        }
        return res;
    }
};
class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> tar=h;
        sort(tar.begin(),tar.end());
        int res=0;
        for(int i=0;i<h.size();i++){
            if(tar[i]!=h[i])
                res++;
        }
        return res;
    }
};
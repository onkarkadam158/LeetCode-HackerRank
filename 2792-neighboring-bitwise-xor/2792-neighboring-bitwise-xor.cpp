class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool res=0;
        for(auto a:derived){
            res=res^a;
        }
        return !res;
    }
};
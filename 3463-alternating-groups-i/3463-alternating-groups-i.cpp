class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& col) {
        int n=col.size(), cnt=0;
        vector<int>temp;
        temp.push_back(col[n-1]);
        for(auto a:col)temp.push_back(a);
        temp.push_back(col[0]);
        for(int i=1;i<n+1;i++){
            if(temp[i]!=temp[i-1] and temp[i]!=temp[i+1]){
                cnt++;
            }
        }
        return cnt;

    }
};
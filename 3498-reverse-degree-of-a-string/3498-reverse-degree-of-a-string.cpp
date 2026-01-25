class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            int ind=s[i]-'a'+1;
            int revInd=26-ind+1;
            sum+=(i+1)*revInd;
        }

        return sum;
    }
};
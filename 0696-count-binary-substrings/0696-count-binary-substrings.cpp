class Solution {
public:
    int countBinarySubstrings(string s) {
        char prev=s[0];
        int count=1;
        vector<int>arr;
        for(int i=1;i<s.size();i++) {
            if(s[i]==prev) {
                count++;
            }
            else {
                prev=s[i];
                arr.push_back(count);
                count=1;
            }
        }
        arr.push_back(count);
        int res=0;
        for(int i=1;i<arr.size();i++) {
            res+=min(arr[i-1],arr[i]);
        }
        return res;
    }
};
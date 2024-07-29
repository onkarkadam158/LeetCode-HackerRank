class Solution {
public:
    unordered_map<string,int>mp;
    string solve(int n, string &temp) {
        if(temp.size()==n) {
            if(mp.find(temp)==mp.end()) {
                return temp;
            }
            return "";
        }
        temp=temp+"0";
        string left=solve(n,temp);
        if(left.size()>0) return left;
        temp.pop_back();

        temp=temp+"1";
        string right = solve(n,temp);
        if(right.size()>0) return right;
        temp.pop_back();

        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto a:nums) mp[a]++;
        string temp="";
        int n=nums[0].size();
        return solve(n,temp);
    }
};
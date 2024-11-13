class Solution {
public:
    //Solution 1 
    vector<vector<int>> bruteforce(vector<int>& nums) {
        set<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        res.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> result;
        for(auto a:res) result.push_back(a);
        return result;
    }
    //SOlution 2
    vector<vector<int>> better(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> res;
        for(int i=0;i<n;i++){
            int num1=nums[i];
            unordered_map<int,int>mp;
            for(int j=i+1;j<n;j++){
                int num2=nums[j];
                if(mp.find(-(num1+num2))!=mp.end()){
                    vector<int>temp={num1,num2,-(num1+num2)};
                    sort(temp.begin(),temp.end());
                    res.insert(temp);
                }
                mp[num2]++;
            }
        }
        
        vector<vector<int>> result(res.begin(),res.end());
        return result;
    }
    
    //Solution 3
    vector<vector<int>> optimal(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end()); //nlogn
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(i!=0 and nums[i-1]==nums[i]) continue;
            int num1=nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                int num2=nums[j],num3=nums[k];
                if((num1+num2+num3) < 0 ){
                    j++;
                }
                else if((num1+num2+num3) > 0) {
                    k--;
                }
                else{
                    res.push_back({num1,num2,num3});
                    j++,k--;
                    while(j<k and num2==nums[j])j++;
                    while(j<k and num3==nums[k]) k--;
                }
            }
        }
        
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // return bruteforce(nums); //time O(N^3 *logM) space O(N^3)

        // return better(nums); //time O(N^2*longM) space O(N^3)

        
        return optimal(nums); //time O(N^2*longM) space O(N^3)
    }
};
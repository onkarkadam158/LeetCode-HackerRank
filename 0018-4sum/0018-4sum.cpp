class Solution {
public:
    #define ll long long
    vector<vector<int>> bruteforce(vector<int>& nums, int target) {
        set<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ll a=nums[i];
            for(int j=i+1;j<n;j++){
                ll b=nums[j];
                for(int k=j+1;k<n;k++){
                    ll c=nums[k];
                    for(int l=k+1;l<n;l++){
                        ll d=nums[l];
                        if( (a+b+c+d)== (target)){
                            vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            res.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> result;
        for(auto a:res) result.push_back(a);
        return result;
    }
    //SOlution 2
    vector<vector<int>> better(vector<int>& nums,int target) {
        set<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=nums[i];
            for(int j=i+1;j<n;j++){
                int b=nums[j];
                unordered_map<int,int>mp;
                for(int k=j+1;k<n;k++){
                    int c=nums[k];

                    if(mp.find(target-(a+b+c))!=mp.end()){
                        vector<int>temp={a,b,c,target-(a+b+c)};
                        sort(temp.begin(),temp.end());
                        res.insert(temp);
                    }

                    mp[target-(a+b+c)]++;
                }
            }
        }
        vector<vector<int>> result(res.begin(),res.end());
        return result;

    }
    //SOlution 3
    vector<vector<int>> optimal(vector<int>& nums,int target) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 and nums[i-1]==nums[i]) continue;
            int a=nums[i];
            for(int j=i+1;j<n;j++){
                if(j!=(i+1) and nums[j-1]==nums[j]) continue;
                int b=nums[j];
                int k=j+1,l=n-1;
                while(k<l){
                    int c=nums[k],d=nums[l];
                    ll sum=a;
                    sum+=b;
                    sum+=c;
                    sum+=d;
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        res.push_back({a,b,c,d});
                        k++,l--;
                        while(k<l and c==nums[k]) k++;
                        while(k<l and d==nums[l]) l--;
                    }
                }
            }
        }

        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // return bruteforce(nums,target); //time O(N^4*logM) space O(N)

        // return better(nums,target);  //time O(N^3*logM) space O(N)

        return optimal(nums,target);  //time O(N^2) space O(N)
    }
};
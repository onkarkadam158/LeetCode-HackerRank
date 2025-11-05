class Solution {
public:
    #define pii pair<int,int> 

    int getSumOfTopX(unordered_map<int,int>mp,int x){
        priority_queue<pii>pq;
        for(auto a:mp){
            pq.push({a.second,a.first});
        }
        int res=0;
        while(!pq.empty() and x--){
            auto top=pq.top();
            pq.pop();
            res+=(top.first*top.second);
        }
        return res;
     }
     vector<int>solution1(vector<int>& nums, int k, int x){
        int n=nums.size();
        vector<int>result;
        unordered_map<int,int>mp;
        priority_queue<pii>pq;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(i>=k-1){
                result.push_back(getSumOfTopX(mp,x));
                mp[nums[i-k+1]]--;
                if(mp[nums[i-k+1]]==0){
                    mp.erase(nums[i-k+1]);
                }
            }
        }
        return result;
     }
    vector<int>bruteforce(vector<int>& nums, int k, int x){
        int n=nums.size();
        vector<int>result;
        for(int i=0;i<n-k+1;i++){
            map<int,int>mp;
            for(int j=i;j<i+k;j++){
                mp[nums[j]]++;
            }

            priority_queue<pii>pq;
            for(auto a:mp){
                pq.push({a.second,a.first});
            }
            int tx=x;
            int temp_res=0;
            while(!pq.empty() and tx--){
                auto top=pq.top();
                pq.pop();
                temp_res+=(top.first*top.second);
            }
            result.push_back(temp_res);

        }

        return result;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        // return bruteforce(nums,k,x);
        return solution1(nums,k,x);
    }
};
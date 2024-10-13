class Solution {
public:
    #define ppii pair<int,pair<int,int>>
    int getPresentCount(vector<vector<int>>& nums,int a,int b){
        int count=0;
        for(auto &lists:nums){
            for(int j=0;j<lists.size();j++){
                int num=lists[j];
                if(a<=num and num<=b){
                    count++;
                    break;
                }
            }
        } 
        return count;
    }
    vector<int> bruteforce(vector<vector<int>>& nums){
        vector<int>arr;
        for(auto &lists:nums){
            for(auto num:lists){
                arr.push_back(num);
            }
        }
        int K=nums.size(),m=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>res(2);
        res[0]=arr[0];
        res[1]=arr[arr.size()-1];
        
        for(int i=0;i<m;i++){
            int a=arr[i];
            for(int j=i+1;j<m;j++){            
                int b=arr[j];
                int count=getPresentCount(nums,a,b);   
                if(count==K){
                    if((b-a)<(res[1]-res[0])){
                        res[1]=b,res[0]=a;
                    }
                    else if((b-a)==(res[1]-res[0]) and (a<res[0])){
                        res[1]=b,res[0]=a;
                    }
                }
            }   
        }
        return res;
    }
    vector<int>optimal(vector<vector<int>>&nums){
        int k=nums.size();
        vector<int>index(k,0),res(2);
        priority_queue<ppii,vector<ppii>,greater<ppii>>pq;
        int maxEle=-1e9;;
        for(int i=0;i<k;i++){
            pq.push({nums[i][0],{i,0}});
            maxEle=max(maxEle,nums[i][0]);
        }
        res[0]=pq.top().first;
        res[1]=1e9;
        while(true){
            auto top=pq.top();
            pq.pop();
            int a=top.first;
            int b=maxEle;
            int i=top.second.first,j=top.second.second;
            
            if((b-a)<(res[1]-res[0])){
                res[1]=b,res[0]=a;
                }
            else if((b-a)==(res[1]-res[0]) and (a<res[0])){
                res[1]=b,res[0]=a;
            }
            j++;
            if(j>=nums[i].size()){
                break;
            }
            int nextEle=nums[i][j];
            pq.push({nextEle,{i,j}});
            maxEle=max(maxEle,nums[i][j]);
        }
        return res;
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // return bruteforce(nums); // Time O(n*m*(n*m) + (n*m log (nm))) space (n*m) for arr array  n no of lists and m average size of each lists

        return optimal(nums);
    }
};
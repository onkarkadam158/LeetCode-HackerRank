class Solution {
public:
    void fun(int i,set<vector<int>>& result,vector<int>& arr,vector<int>& temp,int target){
        if(i>=arr.size()){
            if(target==0)
                result.insert(temp);
            return ;
        }
        if(arr[i]<=target){
            temp.push_back(arr[i]);
            fun(i+1,result,arr,temp,target-arr[i]);
            temp.pop_back();
        }
        fun(i+1,result,arr,temp,target);
    }
     vector<vector<int>>bruteforce(vector<int>& candidates, int target){
        vector<int>temp;
        set<vector<int>>stresult;
        sort(candidates.begin(),candidates.end());
        fun(0,stresult,candidates,temp,target);
        vector<vector<int>>result;
        for(auto a:stresult){
            result.push_back(a);
        }
        return result;
    }
    void optimal(int ind,vector<vector<int>>& result,vector<int>& arr,int target,vector<int>& temp){
        if(target==0){
            result.push_back(temp);
            return ;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind and arr[i]==arr[i-1]) continue;
            if(arr[i]>target){
                return ;
            }
            temp.push_back(arr[i]);
            optimal(i+1,result,arr,target-arr[i],temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //return bruteforce(candidates,target);
        //optimized
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>temp;
        optimal(0,result,candidates,target,temp);
        return result;
       
    }
};





















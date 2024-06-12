class Solution {
public:
    void generate(int i,vector<vector<int>>& result,vector<int>& nums,vector<int>& temp){
        if(i>=nums.size()){
            result.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        generate(i+1,result,nums,temp);
        temp.pop_back();
        generate(i+1,result,nums,temp);
    }
    vector<int>getList(int n,vector<int>& nums){
        vector<int>temp;
        int index=0;
        while(n){
            if(n%2) temp.push_back(nums[index]);
            index++;
            n=n/2;
        }
        return temp;
    }
    vector<vector<int>> bitManipulationApproach(vector<int>& nums){
        vector<vector<int>>result;
        int n=nums.size();
        int size=1<<n;
        for(int i=0;i<size;i++){
            result.push_back(getList(i,nums));
        }
        return result;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>>result;
        // vector<int>temp;
        // generate(0,result,nums,temp);
        // return result;

        return bitManipulationApproach(nums);
    }
};
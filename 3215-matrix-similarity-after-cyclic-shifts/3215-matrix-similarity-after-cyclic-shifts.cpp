class Solution {
public:
    bool isEqual(vector<vector<int>>& temp,vector<vector<int>>&mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=temp[i][j]) return false;
            }
        }
        return true;
    }
    void shilfLeft(vector<int>&nums){
        int n=nums.size();
        int last=nums[0];
        for(int i=0;i<n-1;i++){
            nums[i]=nums[i+1];
        }
        nums[n-1]=last;
    }
    void shilfRight(vector<int>&nums){
        int n=nums.size();
        int first=nums[n-1];
        for(int i=n-1;i>0;i--){
            nums[i]=nums[i-1];
        }
        nums[0]=first;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>temp=mat;
        while(k--){
            for(int i=0;i<mat.size();i++){
                if(i%2==0){
                    shilfLeft(temp[i]);
                }
                else{
                    shilfRight(temp[i]);
                }
            }
        }    
        return isEqual(temp,mat);
    }
};
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long unsigned sum=0;
        for(auto a:chalk)sum+=a;
        k=k%sum;
        int n=chalk.size();
        for(int i=0;i<n;i++){
            if(chalk[i]<=k){
                k-=chalk[i];
            }
            else{
                return i;
            }
        }
        return 0;
    }
};
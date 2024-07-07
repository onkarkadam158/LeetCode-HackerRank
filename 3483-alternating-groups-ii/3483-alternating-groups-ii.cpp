class Solution {
public:
    int bruteforce(vector<int>&colors,int k){
        int n=colors.size(), cnt=0;
        for(int i=0;i<k-1;i++)colors.push_back(colors[i]);
        for(int i=0;i<n;i++){
            int curr=colors[i];
            int flag=0;
            for(int j=i+1;j<i+k;j++){
                if(curr!=colors[j]){
                    curr=colors[j];
                }
                else{
                    flag=1;
                    i=j-1;
                    break;
                }
            }
            if(!flag)cnt++;
        }
        return cnt;
    }
    int optimal(vector<int>&colors,int k){
        int n=colors.size(),cnt=1,res=0;
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        for(int i=1;i<colors.size();i++){
            if(colors[i]!=colors[i-1]) cnt++;
            else cnt=1;
            if(cnt>=k) res++;
        }
        return res;
    }
    int SpaceOptimal(vector<int>&colors,int k){
        int n=colors.size(),cnt=1,res=0;
        for(int i=1;i<n+k-1;i++){
            if(colors[(i+n)%n]!=colors[(i-1+n)%n]) cnt++;
            else cnt=1;
            if(cnt>=k) res++;
        }
        return res;
    }
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // return bruteforce(colors,k);//time O(n^2) space O(K)

        // return optimal(colors,k);//time O(n) space O(K)

        return SpaceOptimal(colors,k);//time O(n) space O(1)
    }
};
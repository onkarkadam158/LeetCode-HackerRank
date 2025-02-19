class Solution {
public:
    bool solve(int ind,string temp,string& res,int &count,int n,int k){
        if(ind==n){
            count++;
            if(count==k){
                res=temp;
                return true;
            }
            return false;
        }
        temp+='z';
        for(int i=0;i<3;i++){
            char c=('a'+i);
            if(ind==0 or temp[ind-1]!=c){
                temp[ind]=c;
                if(solve(ind+1,temp,res,count,n,k)) return true;
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        int count=0;
        string temp="",res="";
        solve(0,temp,res,count,n,k);
        return res;
    }
};
class Solution {
public:
    string solve(int ind,string temp,int n,int& k){
        if(ind==n){
            k--;
            if(k==0){
                return temp;
            }
            return "";
        }
        temp+='z';
        for(int i=0;i<3;i++){
            if(ind==0 or temp[ind-1]!=('a'+i)){
                temp[ind]=('a'+i);
                string t=solve(ind+1,temp,n,k);
                if(t!="") return t;
            }
        }
        return "";
    }
    string getHappyString(int n, int k) {
        string temp="";
        return solve(0,temp,n,k);
    }
};
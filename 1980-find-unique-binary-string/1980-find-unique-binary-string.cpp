class Solution {
public:
    int getDecimal(string s){
        int res=0;
        for(int i=0;i<s.size();i++){
            res=2*res + (s[i]-'0');
        }
        return res;
    }
    string getBinary(int num,int n){
        string res="";
        while(n--){
            res+='0';
        }
        int i=0;
        while(num){
            if(num%2) res[i]='1';
            i++;
            num=num/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string solution1(vector<string>&nums){
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto &a:nums){
            cout<<getDecimal(a)<<" ";
            mp[getDecimal(a)]++;
        }
        string result="";
        for(int i=0;i<pow(2,n);i++){
            if(mp.find(i)==mp.end()){
                result=getBinary(i,n);
                break;
            }
        }
        return result;
    }
    //SOlution 2
    string solution2(int n,string& temp,unordered_map<string,int>&mp){
        if(temp.size()==n){
            if(mp.find(temp)==mp.end()){
                return temp;
            }
            return "";
        }
        temp+='0';
        string res=solution2(n,temp,mp) ;
        if(res.size()==n) return res;
        temp.pop_back();

        temp+='1';
        res=solution2(n,temp,mp) ;
        if(res.size()==n) return res;
        temp.pop_back();

        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        // return solution1(nums); // Without recursion solution
        
        string temp="";
        int n=nums.size();
        unordered_map<string,int>mp;
        for(auto str:nums) mp[str]++;

        return solution2(n,temp,mp);
         
    }
};
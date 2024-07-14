class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0;i<s.size()-1;i++){
            int a=s[i]-'0',b=s[i+1]-'0';
            if((a%2 ==0 and b%2==0) or (a%2 ==1 and b%2==1)  ){
                if(s[i]>s[i+1]){
                    swap(s[i],s[i+1]);
                    return s;
                }
            }
        }
        return s;
    }
};
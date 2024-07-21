class Solution {
public:
    bool isVowel(char c){
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
    }
    bool doesAliceWin(string s) {
        int vowels=0,n=s.size();
        for(auto a:s){
            if(isVowel(a)){
                vowels++;
            }
        }
        if(vowels==0) return false;
        if(vowels%2) return true;
        return true;
    }
};
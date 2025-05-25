class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0,mid=0;
        unordered_map<string,int>mp1,mp2;

        for(auto &word:words){
            if(word[0]==word[1]){
                mp1[word]++;
                mid=max(mid,mp1[word]);
            }
            else{
                mp2[word]++;
            }
        }
        for(auto &word:words){
            if(word[0]!=word[1]){
                string revWord=word;
                reverse(revWord.begin(),revWord.end());
                if(mp2.find(revWord)!=mp2.end()){
                    res+=min(mp2[word],mp2[revWord]);
                    mp2.erase(revWord);
                }
                mp2.erase(word);
            }
        }
        for(auto a:mp1){
            if(a.second==mid){
                mp1.erase (a.first);
                break;
            }
        }
        if(mid%2){
            for(auto a:mp1){
                if(a.second>1){
                    mid+=2*(a.second/2);
                }
            }
        }
        else{
            for(auto a:mp1){
                if(a.second>1){
                    mid+=2*(a.second/2);
                }
            }
            for(auto a:mp1){
                if(a.second%2){
                    mid+=1;
                    break;
                }
            }
        }
        return 4*res+2*mid;
    }
};
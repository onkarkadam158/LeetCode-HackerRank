class Solution {
public:
    int solution1(string s){
        int n=s.size();
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]={i,i};
            }
            else{
                mp[s[i]][1]=i;
            }
        }
        int count=0;
        for(auto a:mp){
            int start=a.second[0],end=a.second[1];
            unordered_set<char>st;
            for(int i=start+1;i<end;i++){
                st.insert(s[i]);
            }
            count+=int(st.size());
        }
        return count;
    }
    int solution2(string s){
        
        int n=s.size();

        unordered_map<char,int>mpRight,mpLeft;
        for(auto a:s) mpRight[a]++;

        mpRight[s[0]]--;
        if(mpRight[s[0]]==0)mpRight.erase(s[0]);

        int count=0;
        unordered_set<string>st;
        mpLeft[s[0]]++;
        for(int i=1;i<n-1;i++){
            char curr=s[i];
            mpRight[curr]--;
            if(mpRight[curr]==0)mpRight.erase(curr);

            for(auto a:mpLeft){
                if(mpRight.find(a.first)!=mpRight.end()) {
                    string res="";
                    res+=a.first;
                    res+=curr;
                    res+=a.first;
                    st.insert(res);
                }
            }

            mpLeft[curr]++;
        }
        return int(st.size());
    }
    int countPalindromicSubsequence(string s) {

        // return solution2(s); more time complexity

        return solution1(s);
    }
};
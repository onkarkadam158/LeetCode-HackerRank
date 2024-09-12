class Solution {
public:
    int bruteforce(string allowed, vector<string>& words){
        int count=0,cnt;
        for(int i=0;i<words.size();i++){
            int cnt=0;
            for(int j=0;j<words[i].size();j++){
                for(int k=0;k<allowed.size();k++){
                    if(words[i][j]==allowed[k]){
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt==words[i].size()) count++;
        }
        return count;
    }
    int mapSolution(string allowed, vector<string>& words){
        int count=0,cnt;
        unordered_map<char,int>mp;
        for(auto a:allowed) mp[a]++;
        for(int i=0;i<words.size();i++){
            int cnt=0;
            for(int j=0;j<words[i].size();j++){
                if(mp.find(words[i][j])!=mp.end()) cnt++;
            }
            if(cnt>=words[i].size())
                count++;
        }
        return count;
    }
    int bitManipulationSolution(string allowed, vector<string>& words){
        int str=0,count=0;
        for(auto a:allowed){
            str+=(1<<(a-'a'));
        }
        for(auto word:words){
            int wordBits=0,cnt=0;
            for(auto ch:word){
                cnt+=((str&(1<<(ch-'a')))!=0);
            }
            count+=(cnt==word.size());
        }
        return count;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        // return bruteforce(allowed,words);
        // return mapSolution(allowed,words);
        return bitManipulationSolution(allowed,words);
    }
};
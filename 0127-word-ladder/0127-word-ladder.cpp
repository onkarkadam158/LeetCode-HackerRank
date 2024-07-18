class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp,vis;
        for(auto a:wordList) mp[a]++;
        if(mp.find(endWord)==mp.end()) return 0;
        int level=1;
        queue<string>que;
        que.push(beginWord);
        vis[beginWord]++;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                string curr=que.front();
                que.pop();
                if(curr==endWord) return level;
                for(int i=0;i<curr.size();i++){
                    string temp=curr;    
                    char c=temp[i];
                    for(int j=0;j<26;j++){
                        temp[i]='a'+j;
                        if(vis.find(temp)==vis.end() and mp.find(temp)!=mp.end()) {
                            vis[temp]++;
                            que.push(temp);
                            cout<<temp<<" ";
                        }
                    }
                    temp[i]=c;
                }
            }
            level++;
        }
        return 0;
    }
};
class Solution {
public:
    vector<char>gene={'A','C','G','T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string,int>words,vis;
        for(auto a:bank)words[a]++;
        queue<string>que;
        que.push(startGene);
        vis[startGene]++;
        int mutations=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                string curr=que.front();
                que.pop();
                if(curr==endGene) return mutations;
                for(int i=0;i<curr.size();i++){
                    char ch=curr[i];
                    for(auto a:gene){
                        curr[i]=a;
                        if(vis.find(curr)==vis.end() and words.find(curr)!=words.end()){
                            que.push(curr);
                            vis[curr]++;
                        }
                    }
                    curr[i]=ch;
                }
            }
            mutations++;
        }

        return -1;
    }
};
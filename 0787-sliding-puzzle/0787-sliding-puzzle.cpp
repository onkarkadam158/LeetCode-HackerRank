class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string end="123450";
        queue<string>que;
        string start="";
        for(auto row:board){
            for(auto x:row) start+=('0'+x);
        }

        unordered_map<int,vector<int>>mp;
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={1,3,5};
        mp[5]={2,4};

        unordered_set<string>vis;
        vis.insert(start);
        que.push(start);
        int level=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                string temp=que.front();
                que.pop();
                if(temp==end) return level;
                for(int ind=0;ind<6;ind++){
                    if(temp[ind]=='0'){
                        for(auto tind:mp[ind]){
                            swap(temp[tind],temp[ind]);
                            if(vis.find(temp)==vis.end()) {
                                que.push(temp);
                                vis.insert(temp);
                            }
                            swap(temp[tind],temp[ind]);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
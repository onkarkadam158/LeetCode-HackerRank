class Solution {
public:
    void print(vector<vector<int>>&v){
        for(auto &a:v){
            for(auto &x:a){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    #define ppii pair<int,pair<int,int>>
    #define ppi pair<int,int>
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());

        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        
        int start=tasks[0][0];
        pq.push({tasks[0][1],tasks[0][2]});
        int i=1;
        vector<int>result;
        while(true){
            if(i>=n ) break;
            while(i<n and (tasks[i][0] <= start) ){
                pq.push({tasks[i][1] ,tasks[i][2]});
                i++;
            }
            if(pq.empty()) {
                pq.push({tasks[i][1] ,tasks[i][2]});
                start=tasks[i][0];
                i++;
            }
            auto top=pq.top();
            pq.pop();
            result.push_back(top.second);
            start+=top.first;
        }   
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
class Solution {
public:
    
//         priority_queue<int>pq;
//         if(first)pq.push(first);
//         if(last)pq.push(last);
        
//         for(int i=0;i<n-1;i++){
//             int diff=start[i+1]-end[i];
//             if(diff) pq.push(diff);
//         }
//         int res=0;
//         while(k-- and pq.size()>1){
//             int top1=pq.top();
//             pq.pop();
            
//             int top2=pq.top();
//             pq.pop();
            
//             pq.push(top1+top2);
            
//         }
//         if(pq.empty()) return 0;
//         return pq.top();
    
    int maxFreeTime(int eventTime, int k, vector<int>& start, vector<int>& end) {
        int n=start.size();
        int first=start[0]-0;
        int last=eventTime -end[n-1];
        
        vector<int>pq;
        if(first)pq.push_back(first);
        
        for(int i=0;i<n-1;i++){
            int diff=start[i+1]-end[i];
            pq.push_back(diff);
        }
        if(last)pq.push_back(last);
        // for(auto a:pq) cout<<a<<" ";
        int sum=pq[0];
        for(int i=1;i<pq.size();i++){
            sum+=pq[i];
            pq[i]+=pq[i-1];
            // cout<<pq[i]<<" ";
        }
        // cout<<endl;
        if(k>=pq.size()) return sum;
        
        int res=pq[k];
        for(int i=k+1;i<pq.size();i++){
            res=max(res,pq[i]-pq[i-k-1]);
        }
        return res;
    }
};
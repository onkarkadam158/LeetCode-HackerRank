class Solution {
public:
    int bruteforce(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<int>taken(n,0);
        while(k--){
            int maxi=INT_MIN,ind=-1;
            for(int i=0;i<n;i++){
                if(!taken[i] and capital[i]<=w){
                    if(profits[i]>maxi){
                        maxi=profits[i];
                        ind=i;
                    }
                }
            }
            if(ind!=-1) {
                taken[ind]=1;
                w+=maxi;
            }
        }
        return w;        
    }
    int optimal(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        priority_queue<int>pq; //max heap which will store the max profit for current w capital
        vector<pair<int,int>>proj;
        for(int i=0;i<n;i++){
            proj.push_back({capital[i],profits[i]});
        }
        sort(proj.begin(),proj.end());
        int i=0;
        while(k--){
            while(i<n and w>=proj[i].first){
                pq.push(proj[i].second);
                i++;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
        }
        return w;        
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // return bruteforce(k,w,profits,capital); //O(k*n) time O(n) space
        return optimal(k,w,profits,capital); //O(k*logn) time O(n) space
    }
};
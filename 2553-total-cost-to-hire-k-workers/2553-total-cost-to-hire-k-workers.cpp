class Solution {
public:
    #define pii pair<int,int>
    long long bruteforce(vector<int>& costs, int k, int candi) {
        int n=costs.size();
        long long res=0;
        vector<int>taken(n,0);
        while(k--){
            int mini=1e6,index=0;
            int i=0,j=0,count=0;
            while(i<n and count<candi ){
                if(!taken[i]){
                    if(mini>costs[i]){
                        mini=costs[i];
                        index=i;
                    }
                    count++;
                }
                i++;
            }
            count=0;
            while(j<n and count<candi){
                if(!taken[n-1-j]){
                    if(mini>costs[n-1-j]){
                        mini=costs[n-1-j];
                        index=n-1-j;
                    }
                    count++;
                }
                j++;
            }
            taken[index]=1;
            res+=costs[index];
        }
        return res;
    }
    long long heapSolution(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        int left=0,right=n-1;
        while(left<n and left<candidates){
            pq1.push(costs[left]);
            left++;
        }
        while(right>=0 and left<=right and (n-1-right)<candidates ){
            pq2.push(costs[right]);
            right--;
        }
        long long totalCost=0;
        while(k--){
            if(!pq1.empty() and pq2.empty()){
                totalCost+=pq1.top();
                pq1.pop();
                if(left<=right){
                    pq1.push(costs[left]);
                    left++;
                }
                continue;
            }
            if(pq1.empty() and !pq2.empty()){
                totalCost+=pq2.top();
                pq2.pop();
                if(left<=right){
                    pq2.push(costs[right]);
                    right--;
                }
                continue;
            }
            if(pq1.top()<=pq2.top()){
                totalCost+=pq1.top();
                pq1.pop();
                if(left<=right){
                    pq1.push(costs[left]);
                    left++;
                }
            }
            else if(pq1.top()>pq2.top()){
                totalCost+=pq2.top();
                pq2.pop();
                if(left<=right){
                    pq2.push(costs[right]);
                    right--;
                }
            }
        }
        return totalCost;
    }
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // return bruteforce(costs,k,candidates);
        return heapSolution(costs,k,candidates);        
    }
};
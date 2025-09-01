class Solution {
public:
    #define pdi pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        double result=0.000000;
        priority_queue<pdi>pq;
        for(int i=0;i<n;i++){
            double pass_i=classes[i][0],total_i=classes[i][1];
            pq.push({(((pass_i+1)/(total_i+1)) - (pass_i/total_i)) ,i});
        }
        while(extraStudents--){
            int ind = pq.   top().second;
            pq.pop();
            
            double pass_i= ++classes[ind][0],total_i= ++classes[ind][1];
            pq.push({(((pass_i+1)/(total_i+1)) - (pass_i/total_i)) ,ind});
        }
        for(int i=0;i<n;i++){
            double pass_i=classes[i][0],total_i=classes[i][1];
            result+=(pass_i/total_i);    
        }
        return (result/double(n));   
    }
};
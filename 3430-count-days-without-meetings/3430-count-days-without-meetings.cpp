class Solution {
public:
    vector<vector<int>> merge_interval(vector<vector<int>>& meetings){
        vector<vector<int>>merged_meetings ;
        int n=meetings.size();
        merged_meetings.push_back(meetings[0]);
        for(int i=1;i<n;i++){
            int m=merged_meetings.size();
            int prev_x=merged_meetings[m-1][0],prev_y=merged_meetings[m-1][1];
            int curr_x=meetings[i][0],curr_y=meetings[i][1];
            if(curr_x<=prev_y){
                merged_meetings[m-1][1]=max(prev_y,curr_y);
            }
            else{
                merged_meetings.push_back(meetings[i]);
            }
        }

        return merged_meetings;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        int count=0;
        sort(meetings.begin(),meetings.end());
        // merge interval
        vector<vector<int>>merged_meetings = merge_interval(meetings);
        // for(auto a:merged_meetings){
        //     for(auto x:a) cout<<x<<" ";
        //     cout<<"\n";
        // }
        int n=merged_meetings.size();
        count+=merged_meetings[0][0]-1;
        for(int i=1;i<n;i++){
            count+=merged_meetings[i][0]-merged_meetings[i-1][1]-1;
        }
        count+=days-merged_meetings[n-1][1];
        return count;
    }
};
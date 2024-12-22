class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int button=events[0][0];
        int maxi=events[0][1],n=events.size();
        for(int i=0;i<n-1;i++){
            if((events[i+1][1]-events[i][1]) > maxi){
                maxi=events[i+1][1]-events[i][1];
                button=events[i+1][0];
            }
            else if((events[i+1][1]-events[i][1]) == maxi){
                button=min(button,events[i+1][0]);
            }
        }
        return button;
    }
};
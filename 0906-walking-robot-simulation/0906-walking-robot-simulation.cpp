class Solution {
public:
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>st;
        for(auto a:obstacles){
            st.insert({a[0],a[1]});
        }
        int direction=0,res=0;
        int x=0,y=0;
        for(auto cmd:commands){
            if(cmd>0){
                while(st.find({x+dir[direction%4][0],y+dir[direction%4][1]})==st.end() and cmd--){
                    x+=dir[direction%4][0];
                    y+=dir[direction%4][1];
                }
            }
            else if(cmd==-1) direction++;
            else direction+=3;
            res=max(res,x*x+y*y);
        }

        return res ;
    }
};
class Solution {
public:
    string getString(int hr,int min){
        if(min<10) {
            return to_string(hr) + ":0" + to_string(min);
        }
        return to_string(hr) + ":" + to_string(min);
    }
    void solve(int idx,int count, vector<int>&time,int hr,int min,vector<string>&res){
        if(hr>11 or min>59) return;
        if(count==0){
            res.push_back(getString(hr,min));
            return;
        }

        for(int i=idx;i<time.size();i++){
            if(i<4){
                solve(i+1,count-1,time,hr+time[i],min,res);
            }
            else{
                solve(i+1,count-1,time,hr,min+time[i],res);//take j
            }
        }
    }
    int countBit(int n){
        int count=0;
        while(n){
            count+=n%2;
            n=n/2;
        }
        return count;
    }
    vector<string> LoopSolution(int turnedOn){
        vector<string>res;
        for(int hr=0;hr<12;hr++){
            for(int min=0;min<60;min++){
                if(countBit(hr) + countBit(min) == turnedOn){
                    res.push_back(getString(hr,min));
                }
            }
        }
        return res;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int>time={1,2,4,8,1,2,4,8,16,32};
        int hr=0,min=0;

        vector<string>res;
        solve(0,turnedOn,time,hr,min,res);
        return res;
    

        // return LoopSolution(turnedOn);
    }
};
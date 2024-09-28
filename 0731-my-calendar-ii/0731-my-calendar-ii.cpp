class MyCalendarTwo {
public:
    vector<vector<int>>single,doub;
    bool check(int a1,int b1,int a2,int b2){
        return max(a1,a2) < min(b1,b2);
    }
    vector<int>getOverlap(int a1,int b1,int a2,int b2){
        return {max(a1,a2),min(b1,b2)};
    }
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        return bruteforce(start,end);
    }
    bool bruteforce(int start,int end){
        for(auto x:doub){
            int x1=x[0],y1=x[1];
            if(check(x1,y1,start,end)){ // double
                return false;
            }
        }
        for(auto a:single){
            int a1=a[0],b1=a[1];
            if(check(a1,b1,start,end)){
                //means single overlap
                vector<int>overlap=getOverlap(a1,b1,start,end);
                doub.push_back(overlap);
            }
        }
        //not in single also
        single.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
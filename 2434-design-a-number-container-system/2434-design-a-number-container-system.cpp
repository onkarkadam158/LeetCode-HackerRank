class NumberContainers {
public:
    map<int,int>mp;
    unordered_map<int,set<int>>mp1;
    NumberContainers() {
        mp.clear();
        mp1.clear();
    }
    
    void change(int index, int number) {
        if(mp.find(index)!=mp.end()){
            int prevNum=mp[index];
            if(mp1.find(prevNum)!=mp1.end()){
                mp1[prevNum].erase(index);
                if(mp1[prevNum].size()==0) mp1.erase(prevNum);
            }
        }
        mp[index]=number;
        mp1[number].insert(index);
    }
    
    int find(int number) {
        if(mp.size()==0) return -1;
        if(mp1.find(number)==mp1.end()) return -1;
        int ind=*mp1[number].begin();
        return ind;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
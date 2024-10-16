class Solution {
public: 
    #define pii pair<int,char>
    string longestDiverseString(int a, int b, int c) {
        string res="";
        priority_queue<pii>pq;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if(c)pq.push({c,'c'});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(res.size()<2 or (res[res.size()-1]!=top.second or res[res.size()-2]!=top.second)){
                res+=top.second;
                top.first--;
                if(top.first>0){
                    pq.push(top);
                }
            }
            else{
                if(pq.empty()) break;
                auto secondTop=pq.top();
                pq.pop();
                res+=secondTop.second;
                secondTop.first--;
                if(secondTop.first) pq.push(secondTop);
                pq.push(top);
            }
        }
        return res;
    }
};
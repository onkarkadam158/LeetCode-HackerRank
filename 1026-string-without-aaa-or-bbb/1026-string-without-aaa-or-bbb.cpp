class Solution {
public:
    #define pii pair<int,char>
    string strWithout3a3b(int a, int b) {
        if(a==0) return "bb";
        if(b==0) return "aa";
        string result="";
        priority_queue<pii>pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(result.size() < 2 or (result[result.size()-1]!=top.second or result[result.size() - 2 ]!= top.second) ){
                result+=top.second;
                top.first--;
                if(top.first){
                    pq.push(top);
                }
            }
            else{
                if(pq.empty()) break;
                auto sTop=pq.top();
                pq.pop();
                result+=sTop.second;
                sTop.first--;
                if(sTop.first){
                    pq.push(sTop);
                }
                pq.push(top);
            }
        }
        return result;
    }
};
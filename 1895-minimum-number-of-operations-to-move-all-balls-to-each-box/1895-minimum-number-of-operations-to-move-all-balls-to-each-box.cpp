class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size(),0);
        for(int i=0;i<boxes.size();i++){
            for(int j=0;j<boxes.size();j++){
                if( boxes[j]=='1' && i!=j)
                    res[i]+=abs(i-j); 
            }
        }
        return res;
    }
};
class Solution {
public:

    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int count=0;

        unordered_set<int> st(arr.begin(), arr.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prev=arr[i];
                int curr=arr[j];
                int len=2;

                while(st.find(prev+curr)!=st.end()){
                    // cout<<prev<<" "<<curr<<" "<<prev+curr<<"\n";
                    int temp=prev;
                    prev=curr;
                    curr+=temp;
                    count=max(count,++len);
                }
                // cout<<"\n";
            }
        }

        return count;
    }
};
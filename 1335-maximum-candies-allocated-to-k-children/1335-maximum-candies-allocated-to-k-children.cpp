class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
            int low=0,high=1e7;
            while(low<high)
            {
                long long int mid=(low+high+1)/2,count=0;
                for(int i=0;i<candies.size();i++)
                    count+=candies[i]/mid;

                if(count<k)
                    high=mid-1;
                else
                    low=mid;
            }
            return low;
    }
};
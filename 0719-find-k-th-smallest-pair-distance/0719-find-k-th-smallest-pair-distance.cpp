class Solution {
public:
    //solution 1
    int bruteforce(vector<int>& nums, int k){
        vector<int>arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                arr.push_back(abs(nums[i]-nums[j]));
            }
        }
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }

    //Solution 2
    int HeapSolution(vector<int>& nums, int k){
        priority_queue<int>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push(abs(nums[i]-nums[j]));
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }

    //Solution 3
    int optimal(vector<int>& nums, int k){
        vector<int>arr(1e6+1,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                arr[(abs(nums[i]-nums[j]))]++;
            }
        }
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>=k) return i;
        }
        return 0;
    }

    //Solution 4
    int getPairsForDistanceMid(vector<int>& nums, int mid){
        int count=0,n=nums.size();
        for(int i=0,j=1;j<n;j++){
            if((nums[j]-nums[i]) <= mid){
                count+=j-i;
            }
            else{
                while(i<j and (nums[j]-nums[i]) > mid) {
                    i++;
                }
                if((nums[j]-nums[i]) <= mid){
                    count+=j-i;
                }
            }
        }
        return count;
    }
    int BinarySearchSolution(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0,high=nums[n-1]-nums[0];
        int result=0;
        while(low<=high){
            int mid=low+(-low+high)/2;
            int pairsForDistanceMid=getPairsForDistanceMid(nums,mid);
            if(pairsForDistanceMid < k){
                low=mid+1;
            }
            else{
                result=mid;
                high=mid-1;
            }
        }
        return result;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        // return bruteforce(nums,k); //time O(n^2*logn) space O(n^2)

        // return HeapSolution(nums,k); //time O(n^2*logk ) space O(k)

        // return optimal(nums,k); //time O(n^2 ) space O(1e6) or O(max(nums[i])) accepted

        return BinarySearchSolution(nums,k); //time O(nlogn + n*log(maxnums[i]) ) space O(1)
    }
};
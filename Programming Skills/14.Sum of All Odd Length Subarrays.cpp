class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        /*
        BruteForce
        int sum=0,k=1;
        for(int i=0;i<arr.size()/2+1;i++)
        {
            for(int z=0;z<(arr.size()-(k-1));z++)
            {
                for(int j=z;j<z+k;j++)
                    sum+=arr[j];    
            }
            k=k+2;
        }
        return sum;
        */
        //Optimal
        int res = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            res += ((((i + 1) * (n - i) + 1) )/ 2 *) (arr[i]);
        }
        return res;
    }
};
/*
Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:

Input: arr = [10,11,12]
Output: 66
 

Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000
*/
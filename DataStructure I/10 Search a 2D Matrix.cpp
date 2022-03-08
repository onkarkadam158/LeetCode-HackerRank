class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //bruteforce
        /*
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                if(matrix[i][j]==target)
                    return true;
        */
        /*Finding the row to search in(with the help of binary search ) and then doing Binary search again on the row  
        int high=matrix.size()-1,low=0;
        while(low<=high)
        {
            int mid=(high+low)/2;
            if(matrix[mid][0]==target)
                return true;
            else if(matrix[mid][0]<target)
            {
                low=mid+1;
            }
            else 
            {              
                high=mid-1;
            }
        }
        int ind=low;
        low=0,high=matrix[ind].size()-1;
            while(low<high)
            {
                int mid=(low+high)/2;
                if(matrix[ind][mid]<target)
                    low=mid+1;
                else if(matrix[ind][mid]>target)
                    high=mid-1;
                else
                    return true;
            }
        return false;*/
        //Considering the entire matrix as a array and apply Binary search
        int m=matrix.size(),n=matrix[0].size();
        int low=0,high=m*n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int ele=matrix[mid/n][mid%n];
            if(ele<target)
                low=mid+1;
            else if(ele>target)
                high=mid-1;
            else
                return true;               
        }
        return false;
    }
};

/*
Search a 2D Matrix

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/
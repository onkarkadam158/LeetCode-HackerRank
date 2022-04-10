

class Solution {
public:
    bool rowwise(vector<vector<char>>arr)
    {
        for(int i=0;i<9;i++)
        {
            map<char,int>mp;
            for(int j=0;j<9;j++)
                if(arr[i][j]!='.' and (arr[i][j]<='9' and arr[i][j]>='0'))
                {
                    if(mp.find(arr[i][j])==mp.end())
                        mp[arr[i][j]]++;
                    else
                        return false;
                }
        }
        return true;
    }
    bool columnwise(vector<vector<char>>arr)
    {
        for(int i=0;i<9;i++)
        {
            map<char,int>mp;
            for(int j=0;j<9;j++)
                if(arr[j][i]!='.' and (arr[j][i]<='9' and arr[j][i]>='0'))
                {
                    if(mp.find(arr[j][i])==mp.end())
                        mp[arr[j][i]]++;
                    else
                        return false;
                }
        }
        return true;
    }
    bool threecross(vector<vector<char>> arr)
    {
        for(int l=0;l<3;l++)
        {
            for(int k=0;k<3;k++)
            {
                map<char,int>mp;
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(arr[i+3*l][j+3*k]!='.' && (arr[i+3*l][j+3*k]<='9' && arr[i+3*l][j+3*k]>='0'))
                         {
                             if(mp.find(arr[i+3*l][j+3*k])==mp.end())
                                mp[arr[i+3*l][j+3*k]]++;
                            else
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return rowwise(board) and columnwise(board) and threecross(board);
    }
};


/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

*/

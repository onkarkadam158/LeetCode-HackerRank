class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    bool checkBoundary(int i,int j,int m,int n){
        return i>=0 and j>=0 and i<m and j<n;
    }
        void print(vector<vector<int>>&v){
        for(auto &a:v){
            for(auto &x:a){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    int countOnes(vector<vector<int>>& grid,int m,int n){
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cnt+=(grid[i][j]);
            }
        }
        return cnt;
    }
    void dfs(int i,int j,vector<vector<int>>& grid,int m,int n){
        grid[i][j]=0;
        for(auto a:dir){
            int dx=i+a[0],dy=j+a[1];
            if(checkBoundary(dx,dy,m,n) and grid[dx][dy]){
                dfs(dx,dy,grid,m,n);
            }  
        }
    }
    int getConnectedComponents(vector<vector<int>>& grid,int m,int n){
        int count=0;
        vector<vector<int>>temp=grid;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j]){
                    dfs(i,j,temp,m,n);
                    count++;
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        //eiher we have to delete zero,one or two 
        int m=grid.size(),n=grid[0].size();
        print(grid);
        int countones = countOnes(grid,m,n);  // zero or one land cell present, that much to be deleted 
        cout<<countones<<"\n";
        if(countones <2) return countones;

        //more than two land cells are present 
        int components=getConnectedComponents(grid,m,n); 
        cout<<components<<"\n";
        if(components>1) return 0; //already disconnected

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int components=getConnectedComponents(grid,m,n);
                    
                    if(components>1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};
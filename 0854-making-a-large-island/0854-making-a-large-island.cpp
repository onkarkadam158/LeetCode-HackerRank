class Solution {
public:
    #define  pii pair<int,int>
    int n;
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<n and j<n;
    }
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int& count){
        vis[i][j]=1;
        count++;
        for(auto a:dir){
            int dx=i+a[0],dy=j+a[1];
            if(check(dx,dy) and grid[dx][dy] and !vis[dx][dy]){
                dfs(dx,dy,grid,vis,count);
            }
        }
    }
    int getSizeOfLargest(vector<vector<int>>& grid ){
        vector<vector<int>>vis(n,vector<int>(n,0));
        int largest=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]){
                    int count=0;
                    dfs(i,j,grid,vis,count);
                    largest=max(largest,count);
                }
            }
        }
        return largest;
    }
    int bruteforceSolution(vector<vector<int>>& grid){
        int sizeOfLargest=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    int temp=getSizeOfLargest(grid);
                    sizeOfLargest=max(sizeOfLargest,temp);
                    grid[i][j]=0;
                }
                else{
                    int temp=getSizeOfLargest(grid);
                    sizeOfLargest=max(sizeOfLargest,temp);
                }
            }
        }
        return sizeOfLargest;
    }
    //Solution 2
    void dfs1(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int& count,int num){
        vis[i][j]=num;
        count++;
        for(auto &a:dir){
            int dx=i+a[0],dy=j+a[1];
            if(check(dx,dy) and grid[dx][dy] and !vis[dx][dy]){
                dfs1(dx,dy,grid,vis,count,num);
            }
        }
    }
    void dfs2(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int& count,int num,vector<vector<int>>&size){
        size[i][j]=count;
        vis[i][j]=1;
        for(auto &a:dir){
            int dx=i+a[0],dy=j+a[1];
            if(check(dx,dy) and grid[dx][dy] and !vis[dx][dy]){
                dfs2(dx,dy,grid,vis,count,num,size);
            }
        }
    }
    void printv(vector<vector<int>>&arr){
        for(auto a:arr){
            for(auto x:a){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    int optmial(vector<vector<int>>& grid){
        vector<vector<int>>vis1(n,vector<int>(n,0)); //number of compo
        vector<vector<int>>vis(n,vector<int>(n,0)); //number of compo
        vector<vector<int>>size(n,vector<int>(n,0)); // size of compo
        int num=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]){
                    int count=0;
                    dfs1(i,j,grid,vis,count,num);
                    dfs2(i,j,grid,vis1,count,num,size);
                    num++;
                }
            }
        }
        // printv(vis);
        // printv(size);
        int largestIsland=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    largestIsland=max(largestIsland,size[i][j]);
                }
                else{
                    unordered_map<int,int>mp;
                    int tempSize=0;
                    for(auto a:dir){
                        int dx=i+a[0],dy=j+a[1];
                        if(check(dx,dy) ){
                            int compo=vis[dx][dy];
                            if(mp.find(compo)==mp.end()){
                                tempSize+=size[dx][dy];
                                mp[compo]++;
                            }
                        }
                    }
                    largestIsland=max(largestIsland,tempSize+1);
                }
            }
        }
        return largestIsland;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        // return bruteforceSolution(grid); //o(n^5) time space O(n^2) time limit exceed

        return optmial(grid); //o(n^3) time space O(n^2) time limit exceed
        
    }
};
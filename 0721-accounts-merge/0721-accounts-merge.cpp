class Solution {
public:
    class DSU{
        public:
            vector<int>parent,size;
            DSU(int n){
                parent.resize(n,0);
                size.resize(n,0);
                for(int i=0;i<n;i++){
                    parent[i]=i;
                }
            }
            void addToDSU(int u,int v){
                int parOfU=getParent(u);
                int parOfV=getParent(v);

                if(parOfU==parOfV) return ;
                if(size[parOfU] < size[parOfV]){
                    parent[parOfU]=parOfV;
                    size[parOfV]++;
                }
                else{
                    parent[parOfV]=parOfU;
                    size[parOfU]++;
                }
            }
            int getParent(int u){
                if(parent[u]==u) return u;
                return parent[u]=getParent(parent[u]);
            }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>mp;//map for the mapping of the emails,corresponding component to which they belong to
        int n=accounts.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mp.find(email)!=mp.end()){
                    int u=mp[email];
                    int v=i;
                    dsu.addToDSU(u,v);
                }
                else{
                    mp[email]=i;
                }
            }
        }
        vector<vector<string>>res(n),result;
        for(auto account:mp){
            string email=account.first;
            int component = account.second;
            int parent=dsu.getParent(component);
            res[parent].push_back(email);
        }
        for(auto &a:res){
            sort(a.begin(),a.end());
        }
        for(int i=0;i<n;i++){
            if(res[i].size()==0) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto a:res[i]){
                temp.push_back(a);
            }
            result.push_back(temp);
        }
        return result;
    }
};
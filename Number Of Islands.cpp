//http://geeksforgeeks.org/problems/number-of-islands/1


class Solution {
  public:
    int pos(int c, int i, int j){
        if(j==(c-1)) return (i+1)*c-1;
        
        return i*c+j;
    }
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    
    void uni(int x,int y){
        int px=find(x), py=find(y);
        
        if(px==py) return;
        
        if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int l=n*m;
        parent.resize(l+1);
        rank.assign(l+1,0);
        iota(parent.begin(),parent.end(),0);
        
        vector<vector<int>> track(n,vector<int>(m,0));
        
        
        vector<int> result;
        
        int count=0;
        
        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        
        for(auto &v:operators){
            int i=v[0], j=v[1];
            if(track[i][j]==1) {
                result.push_back(count);
                continue;
            }
            track[i][j]=1;
            count++; //thought it to be a new island
            for(auto &[x,y]:dir){
                int ni=i+x, nj=j+y;
                if(ni==n || nj==m || ni==-1 || nj==-1 || track[ni][nj]==0) continue;
                if(find(pos(m,i,j))!=find(pos(m,ni,nj))){
                    uni(pos(m,i,j),pos(m,ni,nj));
                    count--;
                }
            }
            
            result.push_back(count);
            
        }
        
        return result;
        
    }
};

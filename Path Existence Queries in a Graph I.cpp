//https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/?envType=daily-question&envId=2026-07-09


class Solution {
public:
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
        else if(rank[py]>rank[px]){
            parent[px]=py;
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.assign(n,0);
        rank.assign(n,0);
        iota(parent.begin(),parent.end(),0);
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff){
                uni(i,i+1);
            }
        }
        vector<bool> result;
        for(auto e:queries){
            if(find(e[0])==find(e[1]))  result.push_back(1);
            else result.push_back(0);
        }

        return result;
        
    }
};

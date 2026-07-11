//https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2026-07-11


class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> totalEdge;

    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

    void uni(int x,int y){
        int px=find(x), py=find(y);
        
        if(px==py) {
            totalEdge[px]++;
            return;
        }

        if(rank[px]>rank[py]){
            parent[py]=px;
            totalEdge[px]++;
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
            totalEdge[py]++;
        }
        else{
            parent[py]=px;
            rank[px]++;
            totalEdge[px]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.assign(n,0);
        rank.assign(n,0);
        totalEdge.assign(n,0);

        iota(parent.begin(),parent.end(),0);


        for(auto e:edges){
            uni(e[0],e[1]);
        }
        unordered_map<int,int> connectedNodes;
        for(int i=0;i<n;i++){
            int p=find(i);
            if(p!=i) totalEdge[p]+=totalEdge[i];

            connectedNodes[p]++;
        }
        int count=0;
        for(auto p:connectedNodes){
            int complete=(p.second*(p.second-1))/2;
            if (complete==totalEdge[p.first]) count++;
        }

        return count;

    }
};

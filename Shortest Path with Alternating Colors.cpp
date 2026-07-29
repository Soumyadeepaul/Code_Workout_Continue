//https://leetcode.com/problems/shortest-path-with-alternating-colors/description/


class Solution {
public:
    vector<int> result;
    int count=0;
    unordered_map<int,vector<int>> red;
    unordered_map<int,vector<int>> blue;
    void dij(int &n){
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq; // cost, node, 0=red, 1=blue
        pq.push({0,0,0});
        pq.push({0,0,1});
        unordered_map<int,unordered_map<int,int>> inq;
        inq[0][0]=1;
        inq[0][1]=1;   //node [col]
        
        while(!pq.empty() && count!=n){
            auto top=pq.top();
            pq.pop();
            int cost=top[0],node=top[1], col=top[2];
            // if(cost>result[node]) continue;
            if(result[node]==INT_MAX) count++;
            result[node]=min(result[node],cost);
            if(col==1){
                for(int i:blue[node]){
                    if(inq[i][0]==1) continue;
                    pq.push({cost+1,i,0});
                    inq[i][0]=1;
                }
            }
            else if(col==0){
                for(int i:red[node]){
                    if(inq[i][1]==1) continue;
                    pq.push({cost+1,i,1});
                    inq[i][1]=1;
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        result.assign(n,INT_MAX);

        for(auto e:redEdges){
            red[e[0]].emplace_back(e[1]);
        }

        for(auto e:blueEdges){
            blue[e[0]].emplace_back(e[1]);
        }

        dij(n);

        for(int i=0;i<n;i++){
            if(result[i]==INT_MAX) result[i]=-1;
        }

        return result;

    }
};

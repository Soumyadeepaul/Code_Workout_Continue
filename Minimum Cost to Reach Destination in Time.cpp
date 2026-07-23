//https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/description/


class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        unordered_map<int,vector<vector<int>>> adjList;
        int dst=0;
        for(auto e:edges){
            adjList[e[0]].push_back({e[1],e[2]});
            adjList[e[1]].push_back({e[0],e[2]});
            dst=max(dst,max(e[0],e[1]));
        }
        vector<vector<int>> dp(dst+1,{INT_MAX,INT_MAX});
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({passingFees[0],0,0});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int pf=top[0], t=top[1], node=top[2];

            if(node==dst) return pf;

            for(auto &nei:adjList[node]){
                int nTime=nei[1]+t;
                int nProcessingFee=pf+passingFees[nei[0]];
                if(nTime>maxTime) continue;
                if(dp[nei[0]][0]<=nProcessingFee && dp[nei[0]][1]<=nTime) continue;
                pq.push({nProcessingFee,nTime, nei[0]});
                dp[nei[0]][0]=nProcessingFee;
                dp[nei[0]][1]=nTime;
            }
        }
        return -1;
    }
};

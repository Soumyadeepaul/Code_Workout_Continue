//https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int r=moveTime.size(), c=moveTime[0].size();

        vector<vector<int>>visited(r,vector<int>(c,INT_MAX));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({0,0,0});

        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int i=top[1], j=top[2], val=top[0];
            if(i==r-1 && j==c-1) return val;

            for(auto &[nx,ny]:dir){
                int x=nx+i, y=ny+j;

                if(x==-1 || y==-1 || x==r || y==c) continue;
                if(visited[x][y]>max(1+val,1+moveTime[x][y])){
                    visited[x][y]=max(1+val,1+moveTime[x][y]);
                    pq.push({max(1+val,1+moveTime[x][y]),x,y});
                }
            }
        }
        return -1;

    }
};

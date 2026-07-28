//https://leetcode.com/problems/flower-planting-with-no-adjacent/description/


class Solution {
public:
    vector<int> result;
    unordered_map<int,vector<int>> mpp;
    unordered_map<int,vector<int>> cantUse;
    vector<bool> inqueue;
    void bck(int x){

        queue<int> q;
        q.push(x);
        inqueue[x]=true;
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            int col;
            for(int j=1;j<=4;j++){
                bool used=false;
                for(int i:cantUse[idx]){
                    if(i==j) {
                        used=true;
                        break;
                    }
                }
                if(!used){
                    col=j;
                    break;
                }
            }
            result[idx]=col;
            for(int i:mpp[idx]){
                if(result[i]==0){
                    cantUse[i].push_back(col);

                    if(!inqueue[i]){
                        q.push(i);
                        inqueue[i]=true;
                    }
                }
            }
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        for(auto p:paths){
            mpp[p[0]].push_back(p[1]);
            mpp[p[1]].push_back(p[0]);
        }
        result.assign(n+1,0);
        inqueue.assign(n+1,false);
        for(int i=1;i<n+1;i++) {
            if(result[i]!=0) continue;
            result[i]=1;
            bck(i);
        }
        return vector<int>(result.begin()+1,result.end());;
    }
};

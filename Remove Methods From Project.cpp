//https://leetcode.com/problems/remove-methods-from-project/description/?envType=daily-question&envId=2026-08-05



class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> adjList;
        for(auto e:invocations){
            adjList[e[0]].push_back(e[1]);
        }

        vector<bool> suspecious(n,0);
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            if(suspecious[top]==1) continue;
            suspecious[top]=1;
            for(int nei:adjList[top]){
                q.push(nei);
            }
            
        }

        for(auto p:adjList){
            int node=p.first;
            vector<int> &temp=p.second;
            if(suspecious[node]) continue;
            for(int nei:temp){
                suspecious[nei]=0;
            }
        }
        int x=2;
        while(x--!=0){
            for(int i=0;i<n;i++){
                if(suspecious[i]==0) q.push(i);
            }
            while(!q.empty()){
                int top=q.front();
                q.pop();
                suspecious[top]=0;
                for(int nei:adjList[top]){
                    if(suspecious[nei]==0) continue;
                    q.push(nei);
                }
                
            }

            for(int i=0;i<n;i++){
                if(suspecious[i]==1) q.push(i);
            }
            while(!q.empty()){
                int top=q.front();
                q.pop();
                for(int nei:adjList[top]){
                    if(suspecious[nei]==0) {
                        suspecious[top]=0;
                        break;
                    }
                }
            }
        }

        

        vector<int> result;
        for(int i=0;i<n;i++){
            if(!suspecious[i]) result.push_back(i);
        }


        return result;

    }
};

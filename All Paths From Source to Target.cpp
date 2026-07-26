//https://leetcode.com/problems/all-paths-from-source-to-target/description/


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int n=graph.size()-1;
        queue<pair<int,vector<int>>> q;
        q.push({0,{0}});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            if(top.first==n){
                result.push_back(top.second);
                continue;
            }
            for(int i:graph[top.first]){
                top.second.push_back(i);
                q.push({i,top.second});
                top.second.pop_back();
            }
        }
        return result;
    }
};

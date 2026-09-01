//https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/


class Solution {
public:
    unordered_map<int, vector<int>> adj;
    long long totalFuel=0;
    set<int> visited;
    vector<long long> helper(int node,int height, int &seats){


        long long fuel=0;
        long long person=0;
        visited.insert(node);
        for(auto nei:adj[node]){
            if(visited.count(nei)) continue;
            auto get=helper(nei,height+1,seats);
            person+=get[0];
            fuel+=get[1];
        }
        if(node!=0) person+=1; //self
        
        long long complete=0;
        long long remaining=0;
        complete=person/seats;
        remaining=person%seats;
        totalFuel+=fuel;
        totalFuel+=complete*height;
        if(remaining==0) return {0,0}; //no extra person
        return {remaining,1}; //new car starts
        

    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        for (auto r:roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }

        helper(0,0,seats);

        return totalFuel;

    }
};

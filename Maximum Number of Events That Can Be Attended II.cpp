//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/


class Solution {
public:
    vector<vector<int>> dp;
    int l;
    int helper(vector<vector<int>>& events, int k, int idx, int attended){
        if(idx==l || attended==k) return 0;
        if(dp[idx][attended]!=-1) return dp[idx][attended];

        // not take
        dp[idx][attended]=helper(events,k,idx+1,attended);

        // take
        auto it=upper_bound(events.begin(),events.end(),events[idx][1],
        [](const int &b, const vector<int> &a){
            return b<a[0];
        })-events.begin();
        int get=helper(events,k,it,attended+1)+events[idx][2];
        return dp[idx][attended]=max(dp[idx][attended],get);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        l=events.size();
        dp.assign(l,vector<int>(k,-1));
        sort(events.begin(),events.end());

        return helper(events,k,0,0);
    }
};

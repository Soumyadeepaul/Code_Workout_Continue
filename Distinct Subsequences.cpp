//https://leetcode.com/problems/distinct-subsequences/description/


class Solution {
public:
    vector<vector<int>> dp;
    int helper(string &s, string &t, int i, int j){
        if(j==t.size()){
            return 1;
        }
        
        if(i==s.size()) return 0;
        if(dp[i][j]>-1) return dp[i][j];
        if(dp[i][j]==-1) dp[i][j]=0;
        if(s[i]==t[j]){
            dp[i][j]+=helper(s,t,i+1,j+1);
        }
        dp[i][j]+=helper(s,t,i+1,j);
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        dp.assign(s.size(),vector<int>(t.size(),-1));
        return helper(s,t,0,0);
    }
};

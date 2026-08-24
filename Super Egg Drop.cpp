//https://leetcode.com/problems/super-egg-drop/description/



class Solution {
public:
    vector<vector<int>> dp;
    int helper(int e, int d){
        if(e==0 || d==0) return 0;
        if(dp[e][d]!=-1) return dp[e][d];

        return dp[e][d]=helper(e,d-1)+1+helper(e-1,d-1);
    }
    int superEggDrop(int k, int n) {
        dp.assign(k+1,vector<int>(n+1,-1));
        int d=0;
        while(helper(k,d)<n){
            d++;
        }
        return d;
    }
};


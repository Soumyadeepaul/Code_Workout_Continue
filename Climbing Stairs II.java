//https://leetcode.com/problems/climbing-stairs-ii/description/?envType=daily-question&envId=2026-11-10


class Solution {
    public int helper(int n, int i, int[] cost, int[] dp){
        if(i==n-1){
            return 0;
        }
        if(dp[i]!=Integer.MAX_VALUE){
            return dp[i];
        }
        if(i+1<n){
            dp[i]=Math.min(dp[i],helper(n, i + 1, cost, dp) + cost[i+1] + (i+1 - i) * (i+1 - i));
        }
        if(i+2<n){
            dp[i]=Math.min(dp[i],helper(n, i + 2, cost, dp) + cost[i+2] + (i+2 - i) * (i+2 - i));
        }
        if(i+3<n){
            dp[i]=Math.min(dp[i],helper(n, i + 3, cost, dp) + cost[i+3] + (i+3 - i) * (i+3 - i));
        }

        return dp[i];

    }
    public int climbStairs(int n, int[] costs) {
        int[] c= new int[n+1];
        int[] dp= new int[n+1];
        c[0]=0;
        for(int i=1;i<=n;i++){
            c[i]=costs[i-1];
        }
        for(int i=0;i<=n;i++){
            dp[i]=Integer.MAX_VALUE;
        }
        dp[0]=helper(n+1,0,c, dp);
        return dp[0];
    }
}

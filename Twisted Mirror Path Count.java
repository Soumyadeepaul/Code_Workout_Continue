//https://leetcode.com/problems/twisted-mirror-path-count/description/?envType=daily-question&envId=2026-10-31


class Solution {
    int r;
    int c;
    int[][][] dp;
    int mod=(int)Math.pow(10,9)+7;
    public int helper(int[][] grid,int i, int j, int dir){ //dir = 0 up to down... 1 left to right
        if(i<0 || j<0 || i>=r || j>=c){
            return 0;
        }
        if(i==r-1 && j==c-1){
            return 1;
        }

        if(dp[i][j][dir]!=-1){
            return dp[i][j][dir];
        }
        dp[i][j][dir]=0;
        if(grid[i][j]==1){
            if(dir==0){
                dp[i][j][dir]=(dp[i][j][dir]+helper(grid,i,j+1,1))%mod;
            }
            else if(dir==1){
                dp[i][j][dir]=(dp[i][j][dir]+helper(grid,i+1,j,0))%mod;
            }
        }
        else{
            dp[i][j][dir]=(dp[i][j][dir]+helper(grid,i,j+1,1))%mod;
            dp[i][j][dir]=(dp[i][j][dir]+helper(grid,i+1,j,0))%mod;
        }
        return dp[i][j][dir];
    }
    public int uniquePaths(int[][] grid) {
        r=grid.length;
        c=grid[0].length;
        dp=new int[r][c][2];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int k=0;k<2;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return helper(grid,0,0,0);

    }
}

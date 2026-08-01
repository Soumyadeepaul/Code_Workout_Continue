//https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-01


class Solution {
public:
    int total;
    vector<vector<int>> dp;
    int helper(vector<int>& nums,int i, int j){
        if(i>j) return 0;
        if(i==j) return dp[i][j]=nums[i];

        if(dp[i][j]!=-1) return dp[i][j];

        int a,b;
        a=nums[i]+min(helper(nums,i+2,j),helper(nums,i+1,j-1));
        b=nums[j]+min(helper(nums,i,j-2),helper(nums,i+1,j-1));

        return dp[i][j]=max(a,b);
    }
    bool predictTheWinner(vector<int>& nums) {
        total=accumulate(nums.begin(),nums.end(),0);
        int l=nums.size();
        dp.assign(l,vector<int>(l,-1));

        int a=helper(nums,0,l-1);
        int b=total-a;
        return a>=b;
    }
};

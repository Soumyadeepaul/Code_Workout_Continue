//https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-ii/description/


class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& nums, int val, int i ,int j){
        if(j-i<=0){
            return 0;
        }
        // 3 conditions
        if(dp[i][j]!=-1) return dp[i][j]; //as val becoming fix after 1st oprtations
        int ans=0;

        if(nums[i]+nums[j]==val){
            ans=helper(nums,val,i+1,j-1)+1;
        }
        if(i<nums.size()-1 && nums[i]+nums[i+1]==val){
            ans=max(ans,helper(nums,val,i+2, j)+1);
        }
        if(j>0 && nums[j-1]+nums[j]==val){
            ans=max(ans,helper(nums,val,i, j-2)+1);
        }
        return dp[i][j]=ans;
    }
    int maxOperations(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        int maxi=*max_element(nums.begin(),nums.end());
        dp.assign(j+1,vector<int>(j+1,-1));
        int ans=helper(nums,nums[i]+nums[j],i+1, j-1)+1;
        ans=max(ans,helper(nums,nums[i]+nums[i+1],i+2, j)+1);
        ans=max(ans,helper(nums,nums[j-1]+nums[j],i, j-2)+1);
        return ans;
    }
};

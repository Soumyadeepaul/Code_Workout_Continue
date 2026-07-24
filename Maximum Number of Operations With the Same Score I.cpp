//https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-i/description/


class Solution {
public:
    int result=0;
    void helper(vector<int>& nums, int val, int count, int i ,int j){
        result=max(result,count);
        if(j-i<=0){
            return;
        }
        if(i<nums.size()-1 && nums[i]+nums[i+1]==val){
            helper(nums,val,count+1,i+2,j);
        }
    }
    int maxOperations(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        helper(nums,nums[i]+nums[i+1],1,i+2, j);
        return result;
    }
};

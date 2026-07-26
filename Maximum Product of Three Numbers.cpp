//https://leetcode.com/problems/maximum-product-of-three-numbers/?envType=daily-question&envId=2026-07-26


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result=0;
        int l=nums.size();
        int f=nums[l-1]*nums[l-2]*nums[l-3];
        int s=nums[0]*nums[1]*nums[l-1];
        return max(f,s);
    }
};

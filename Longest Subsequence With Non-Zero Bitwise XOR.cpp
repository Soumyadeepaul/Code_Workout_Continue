//https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/?envType=daily-question&envId=2026-08-15



class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int result=0;
        for(int i:nums){
            result^=i;
        }
        if(result!=0) return nums.size();
        unsigned long long total=0;
        for(int i:nums){
            total+=i;
        }
        return (total==0)? 0:nums.size()-1;
    }
};

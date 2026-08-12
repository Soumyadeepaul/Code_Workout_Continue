//https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> helper;
        int result=0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            helper[nums[j]]++;
            if(helper[nums[j]]<=k){
                result=max(result,j-i+1);
            }
            else{
                for(;i<j;i++){
                    helper[nums[i]]--;
                    if(nums[i]==nums[j]) {
                        i++;
                        break;
                    }
                }
            }
        }
        return result;
    }
};

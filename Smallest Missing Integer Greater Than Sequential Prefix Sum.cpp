//https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/?envType=daily-question&envId=2026-08-11


class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int summ=nums[0];
        if(nums.size()==1) return summ+1;
        unordered_set<int>uni(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                summ+=nums[i];
            }
            else{
                while(summ){
                    if(uni.count(summ))summ++;
                    else return summ;
                }
            }
        }
        return summ;
    }
};

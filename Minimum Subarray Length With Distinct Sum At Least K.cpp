//https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k/description/?envType=problem-list-v2&envId=sliding-window


class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int i=0,j=0,l=nums.size();

        int result=INT_MAX;
        unordered_map<int,int> uni;
        int summ=0;
        while(j<l){
            
            if(uni.count(nums[j])){}
            else summ+=nums[j];
            uni[nums[j]]++;
            while(summ>=k){
                result=min(result,j-i+1);
                uni[nums[i]]--;
                if(uni[nums[i]]==0){
                    uni.erase(nums[i]);
                    summ-=nums[i];
                }
                i++;
                if(i==j && summ>=k) return 1;
            }
            j++;
            
        }
        return result==INT_MAX? -1: result;
    }
};

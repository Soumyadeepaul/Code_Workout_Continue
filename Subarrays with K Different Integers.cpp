//https://leetcode.com/problems/subarrays-with-k-different-integers/description/


class Solution {
public:
    int helper(vector<int>& nums,int k){
        int count=0;
        unordered_map<int,int> store;
        int i=0,j=0,l=nums.size();

        while(j<l){
            store[nums[j]]++;
            int size=store.size();
            while(size>k){
                store[nums[i]]--;
                if(store[nums[i]]==0){
                    store.erase(nums[i]);
                    size--;
                }
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return helper(nums,k)-helper(nums,k-1);
    }
};

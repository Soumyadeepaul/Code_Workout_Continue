//https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/description/


class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        
        int i=0,j=0,result=INT_MAX;
        //Total Summ
        unsigned long long total=0;
        for(int i:nums) total+=i;
        //Number of elements already traversed
        int extraJ=(target/total)*nums.size();
        //New Target
        target=target%total;
        //if target==0 already reached
        if(target==0) return extraJ;

        //atleast traverse twice
        int l=2*nums.size();
        int summ=0;
        while(j<l){
            int temp=j%nums.size();
            summ+=nums[temp];

            while(summ>=target){
                if(summ==target) result=min(result,abs(j+extraJ-i+1));
                summ-=nums[i];
                i++;
                i=i%nums.size();
            }

            j++;
        }
        return (result==INT_MAX)? -1:result;
    }
};

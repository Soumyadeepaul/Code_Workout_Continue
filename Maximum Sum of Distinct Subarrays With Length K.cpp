//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/



class Solution {
public:
    typedef long long ll;
    void shortner(unordered_map<int,int> &freq, int &i, ll &summ, vector<int>& nums, int &j){
        while(nums[i]!=nums[j]){
            freq[nums[i]]--;
            summ-=nums[i];
            i++;
        }
        freq[nums[i]]--;
        summ-=nums[i];
        i++;
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll result=0;

        ll summ=0;
        unordered_map<int,int> freq;
        int i=0;
        for(int j=0;j<nums.size();j++){
            freq[nums[j]]++;
            summ+=nums[j];
            if(freq[nums[j]]==2){
                shortner(freq,i,summ,nums,j);
            }
            if(j-i+1==k){    
                result=(result<summ)?summ:result;
                freq[nums[i]]--;
                summ-=nums[i];
                i++;
            }
        }
        return result;
    }
};

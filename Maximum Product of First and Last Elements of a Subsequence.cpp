//https://leetcode.com/problems/maximum-product-of-first-and-last-elements-of-a-subsequence/description/


class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int l=nums.size();
        vector<long long> neg(l);
        vector<long long> pos(l);
        neg[l-1]=nums[l-1];
        pos[l-1]=nums[l-1];
        for(long long i=l-2;i>-1;i--){
            neg[i]=min<long long>(neg[i+1],nums[i]);
            pos[i]=max<long long>(pos[i+1],nums[i]);
        }

        long long result=LONG_LONG_MIN;
        m-=1;
        for(long long i=0;i<l-m;i++){
            result=max<long long>(result,max<long long>(1ll*nums[i]*neg[i+m],1ll*nums[i]*pos[i+m]));
        }
        return result;
    }
};

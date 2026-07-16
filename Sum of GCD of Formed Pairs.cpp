//https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/?envType=daily-question&envId=2026-07-16


class Solution {
public:
    long long gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        vector<long long> store;
        int maxi=nums[0];
        for(int i:nums){
            maxi=max(maxi,i);
            store.push_back(gcd(i,maxi));
        }
        sort(store.begin(),store.end());

        int i=0, j=store.size()-1;
        long long result=0;

        while(i<j){
            result+=gcd(store[i++],store[j--]);
        }
        return result;
    }
};

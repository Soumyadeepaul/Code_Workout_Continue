//https://leetcode.com/problems/number-of-unique-xor-triplets-i/description/?envType=daily-question&envId=2026-07-23


class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int l=nums.size();
        if(l<3) return l;
        int idx=0;
        while(l){
            idx++;
            l/=2;
        }
        return pow(2,idx);
    }
};

//https://leetcode.com/problems/construct-uniform-parity-array-ii/description/?envType=daily-question&envId=2026-09-03


class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd=1;
        bool even=1;
        for(int i:nums1){
            if(i&1) even=0;
            else odd=0;
        }
        if(odd||even) return odd||even;

        int minEven=INT_MAX;
        int minOdd=INT_MAX;
        for(int i:nums1){
            if(i&1){
                minOdd=min(minOdd,i);
            }
            else {
                minEven=min(minEven,i);
            }
        }

        //try odd
        bool notfound=0;
        for(int i:nums1){
            if(i&1){}
            else{
                if(i-minOdd>=1){}
                else {
                    notfound=1;
                    break;
                }
            }
        }
        
        if(notfound==0) return true;
        notfound=0;

        //try Even
        for(int i:nums1){
            if(i&1){
                if(i-minOdd>=1){}
                else {
                    notfound=1;
                    break;
                }
            }
        }
        
        if(notfound==0) return true;
        return false;
    }
};

//https://leetcode.com/problems/maximum-product-of-two-digits/description/?envType=daily-question&envId=2026-07-25

class Solution {
public:
    int maxProduct(int n) {
        int l=0, l1=0;

        while(n!=0){
            int rem=n%10;
            n/=10;
            if(rem>=l){
                l1=l;
                l=rem;
            }
            else if(rem>l1){
                l1=rem;
            }
        }
        return l*l1;
    }
};

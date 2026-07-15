//https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/?envType=daily-question&envId=2026-07-15


class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int summOdd = (n*(2*1+(n-1)*2))/2;
        int summEven = (n*(2*2+(n-1)*2))/2;
        return gcd(summOdd,summEven);
    }
};

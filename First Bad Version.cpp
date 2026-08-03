//https://leetcode.com/problems/first-bad-version/description/


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long i=1, j=n;

        while(i<j){
            long long mid=(i+j)/2;
            if(isBadVersion(mid)){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return j;
    }
};

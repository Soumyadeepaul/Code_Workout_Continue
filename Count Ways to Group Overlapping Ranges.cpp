//https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/


class Solution {
public:
    int mod=1e9+7;
    int power(int n){
        if(n==1) return 2;
        long long result=1;
        long long power=2;

        while(n){
            if(n%2==1){
                result=(1ll*result*power)%mod;
            }
            power=(1ll * power*power)%mod;
            n/=2;
        }
        return result;
    }
    int countWays(vector<vector<int>>& ranges) {
        int count=ranges.size();
        sort(ranges.begin(),ranges.end());
        int end=ranges[0][1];
        for(int i=1;i<ranges.size();i++){
            if(end<ranges[i][0]){
                end=ranges[i][1];
            }
            else{
                count-=1;
                end=max(end,ranges[i][1]);
            }
        }
        return power(count);
    }
};

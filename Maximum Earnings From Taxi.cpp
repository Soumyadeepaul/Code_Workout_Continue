//https://leetcode.com/problems/maximum-earnings-from-taxi/description/


class Solution {
public:
    typedef long long ll;
    vector<ll> dp;
    int l;
    ll helper(vector<vector<int>>& rides, int idx){
        if(idx==rides.size()){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        //not take
        dp[idx]=helper(rides,idx+1);

        //take  TLE
        // bool found=0;
        // for(int i=idx+1;i<l;i++){
        //     if(rides[i][0]>=rides[idx][1]){
        //         ll get=helper(rides,i)+(rides[idx][1]-rides[idx][0]+rides[idx][2]);
        //         dp[idx]=(dp[idx]>get)?dp[idx]:get;
        //         found=1;
        //         break;
        //     }
        // }
        // if(found==0) {
        //     int get=helper(rides,l)+(rides[idx][1]-rides[idx][0]+rides[idx][2]);
        //     dp[idx]=(dp[idx]>get)?dp[idx]:get;
        // }

        //take
        auto it=lower_bound(rides.begin(),rides.end(),rides[idx][1],
        [](const vector<int>& a,const int &b){
            return a[0]<b;
        }
        )-rides.begin();
        ll get=helper(rides,it)+(rides[idx][1]-rides[idx][0]+rides[idx][2]);
        dp[idx]=(dp[idx]>get)?dp[idx]:get;
        return dp[idx];

    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        l=rides.size();
        dp.assign(l,-1);
        sort(rides.begin(),rides.end());
       
        return helper(rides,0);
    }
};

//https://leetcode.com/problems/stone-game-iv/?envType=daily-question&envId=2026-08-10



class Solution {
public:
    vector<vector<int>> dp;
    set<int> sq;
    int helper(int remaining, bool turn){ //turn = 0 alice
        if(remaining==0){
            if(turn==1) dp[turn][remaining]=true; //opponent has nothing to remove   alice wins
            if(turn==0) dp[turn][remaining]=false;
            return dp[turn][remaining];
        }
        if(dp[turn][remaining]!=-1) return dp[turn][remaining]; 

        bool ans=(turn)?1:0;
        for(auto it=sq.begin(); it!=sq.end();it++){
            if(*it> remaining) break;
            if(!turn) {
                ans=max(ans,(bool)helper(remaining-*it,!turn));
                if(ans==1) break;
            }
            if(turn) {
                ans=min(ans,(bool)helper(remaining-*it,!turn));
                if(ans==0) break;
            }
        }
        return dp[turn][remaining]=ans;
    }
    bool winnerSquareGame(int n) {
        for(int i=1;i<=n;i++){
            int val=i*i;
            if(val>n) break;
            sq.insert(val);
        }
        dp.assign(2,vector<int>(n+1,-1));

        return (helper(n,0)==1)? true:false;
    }
};

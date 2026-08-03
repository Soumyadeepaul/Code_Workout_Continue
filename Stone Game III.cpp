//https://leetcode.com/problems/stone-game-iii/description/?envType=daily-question&envId=2026-08-03


class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& stoneValue, int idx){
        if(idx>=stoneValue.size()) return 0;

        if(dp[idx][0]!=INT_MIN) return max(dp[idx][0],max(dp[idx][1],dp[idx][2]));
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        a=stoneValue[idx]+ min(helper(stoneValue,idx+2),min(helper(stoneValue,idx+3),helper(stoneValue,idx+4)));
        if(idx+1<stoneValue.size())
        b=stoneValue[idx]+stoneValue[idx+1]+ min(helper(stoneValue,idx+3),min(helper(stoneValue,idx+4),helper(stoneValue,idx+5)));
        if(idx+1+1<stoneValue.size())
        c=stoneValue[idx]+stoneValue[idx+1]+stoneValue[idx+2]+ min(helper(stoneValue,idx+4),min(helper(stoneValue,idx+5),helper(stoneValue,idx+6)));

        dp[idx][0]=a; //1 element
        dp[idx][1]=b; //2 element
        dp[idx][2]=c; //3 element

        return max(dp[idx][0],max(dp[idx][1],dp[idx][2]));

    }
    string stoneGameIII(vector<int>& stoneValue) {
        int total=accumulate(stoneValue.begin(),stoneValue.end(),0);
        int l=stoneValue.size();

        dp.assign(l,vector<int>(3,INT_MIN));
        int alice=helper(stoneValue,0);
        int bob=total-alice;
        if(alice==bob) return "Tie";
        return (alice>bob) ? "Alice":"Bob";
    }
};

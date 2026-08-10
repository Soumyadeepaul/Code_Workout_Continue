//https://leetcode.com/problems/longest-palindromic-subsequence/description/


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l=s.size();
        vector<vector<int>> dp(l,vector<int>(l,0));

        for(int gap=0;gap<l;gap++){
            for(int i=0;i<l;i++){
                int j=i+gap;
                if(j>=l) break;
                if(i==j) dp[i][j]=1;
                else{
                    if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                    else dp[i][j]=max(dp[i][j-1],dp[i+1][j]); 
                }
            }
        }
        return dp[0][l-1];
    }
};

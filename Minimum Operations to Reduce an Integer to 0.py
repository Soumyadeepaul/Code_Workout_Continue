#https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/

class Solution:
    dp=dict()
    def helper(self,n):
        global dp
        
        if n==0 or n==1:
            return n
        if n not in self.dp:
            self.dp[n]=count
        
        else:
            return self.dp[n]

        val=1
        while val*2<n:
            val*=2
        self.dp[n]=1+min(self.helper(2*val-n),self.helper(n-val))
        return self.dp[n]
        
    def minOperations(self, n: int) -> int:
        
        return self.helper(n)

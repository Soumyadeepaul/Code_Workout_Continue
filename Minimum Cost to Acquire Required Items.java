//https://leetcode.com/problems/minimum-cost-to-acquire-required-items/description/?envType=daily-question&envId=2026-11-11


class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // 2 possible cases
        // 1 + 2
        // 3
        //partial 3 then 1/2

        long result;

        result=(long)need1*cost1 + (long)need2*cost2;

        result=Math.min(result,(long)costBoth*(Math.max(need1,need2)));

        long mini = (long)Math.min(need1,need2);
        long partial1 = (long)costBoth*mini;

        long partial2;
        if(need1>need2){
            result=Math.min(result,(long)partial1+(long)(need1-need2)*cost1);
        }
        else{
            result=Math.min(result,(long)partial1+(long)(need2-need1)*cost2);
        }

        return result;
    }
}

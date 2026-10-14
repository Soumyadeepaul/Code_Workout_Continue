//https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/?envType=daily-question&envId=2026-10-14


class Solution {
    public String maxSumOfSquares(int num, int sum) {
        String result="9".repeat(sum/9);
        if(sum%9!=0)result+=sum%9;
        int l =result.length();
        if(num>l)   result+="0".repeat(num-l);
        if(l>num) return "";
        return result;
    }
}

//https://leetcode.com/problems/reverse-degree-of-a-string/description/?envType=daily-question&envId=2026-09-20


class Solution {
    public int reverseDegree(String s) {
        Integer result= new Integer(0);
        for(int i=0;i<s.length();i++){
            result+=(i+1)*(26-((int)s.charAt(i)-97));
        }
        return result;
    }
}

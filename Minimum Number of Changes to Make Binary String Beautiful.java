//https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/?envType=daily-question&envId=2026-11-18

class Solution {
    public int minChanges(String s) {
        int count=0;
        for(int i=0;i<s.length()-1;i+=2){
            char a= s.charAt(i);
            char b= s.charAt(i+1);
            if(a!=b){
                count+=1;
            }
        }
        return count;
    }
}

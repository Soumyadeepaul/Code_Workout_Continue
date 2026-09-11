//https://leetcode.com/problems/unique-3-digit-even-numbers/description/?envType=daily-question&envId=2026-09-11


class Solution {
    public int totalNumbers(int[] digits) {
        Set<Integer> unique= new HashSet<>();
        int l=digits.length;
        for(int i=0;i<l;i++){
            if(digits[i]==0) continue;
            
            for(int j=0;j<l;j++){
                if(i==j) continue;
                for(int k=0;k<l;k++){
                    if(i==k || j==k) continue;
                    if(digits[k]%2!=0) continue;
                    unique.add(digits[i]*100+digits[j]*10+digits[k]);
                }
            }
        }
        return unique.size();
    }
}

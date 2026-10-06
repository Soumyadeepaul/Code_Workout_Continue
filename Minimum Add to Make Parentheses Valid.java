//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2026-10-06


class Solution {
    public int minAddToMakeValid(String s) {
        int count=0;
        Stack<Character> st= new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(') {
                st.push('(');
            }
            else{
                if(!st.isEmpty() && st.peek()=='(') st.pop();
                else count+=1;
            }
        }
        while(!st.isEmpty()){
            st.pop();
            count+=1;
        }
        return count;
    }
}

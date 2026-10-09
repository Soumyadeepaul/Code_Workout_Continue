//https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/?envType=daily-question&envId=2026-10-09


class Solution {
    public int minInsertions(String s) {
        Stack<Character> st= new Stack<>();
        int count=0;
        int i=0;
        while(i<s.length()){
            char ch=s.charAt(i);
            if(ch=='(') st.push(ch);
            else{
                if(i+1<s.length() && s.charAt(i+1)==')'){
                    if(st.isEmpty()) count+=1;
                    else st.pop();
                    i+=1; //one extra jump
                }
                else{
                    if(st.isEmpty()) count+=1;
                    else st.pop();
                    count+=1;
                }
            }
            i+=1;
        }
        return count+2*st.size();
    }
}

//https://leetcode.com/problems/remove-invalid-parentheses/description/?envType=daily-question&envId=2026-10-07

class Solution {
    Set<String> result = new HashSet<>();
    int largest=0;
    public void helper(String s, int i, String temp, int open, int close){
        if(i==s.length()){
            if(open==close){
                if(open+close>largest) {
                    result.clear();
                    largest=open+close;
                }
                if(open+close==largest)
                    result.add(temp);
            }
            return;
        }
        char ch= s.charAt(i);
        if(ch=='('){
            helper(s,i+1,temp+ch,open+1,close);
            helper(s,i+1,temp,open,close);
        }
        else if(ch==')'){
            if(open>close){
                helper(s,i+1,temp+ch,open,close+1);
            }
            helper(s,i+1,temp,open,close);
        }
        else{
            helper(s,i+1,temp+ch,open,close);
        }
    }
    
    public List<String> removeInvalidParentheses(String s) {
        
        String temp="";
        helper(s,0,temp,0,0);
        return new ArrayList<>(result);
    }
}

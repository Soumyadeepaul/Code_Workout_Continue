//http://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2026-09-27

class Reverser {
    public String helper(String s) {
        StringBuilder sb = new StringBuilder(s);
        int i = 0;
        int j = sb.length() - 1;
        
        while (i < j) {
            char temp = sb.charAt(i);
            sb.setCharAt(i, sb.charAt(j));
            sb.setCharAt(j, temp); 
            i++;
            j--;
        }
        return sb.toString();
    }
}

class BusinessLogic{
    private String result="";
    Reverser r;
    BusinessLogic(){
        this.r=new Reverser();
    }

    public void logic(String s){
        int l=s.length();
        Stack<String> st = new Stack<>();
        for(int i=0;i<l;i++){
            if(s.charAt(i)!=')'){
                st.push(String.valueOf(s.charAt(i)));
            }
            else{
                String temp="";
                while(!st.isEmpty() && !st.peek().equals("(")){
                    temp+=st.pop();
                }
                st.pop();
                for(int j=0;j<temp.length();j++){
                    st.push(String.valueOf(temp.charAt(j)));
                }
            }
        }
        while(!st.isEmpty()){
            result+=st.pop();
        }
        result=r.helper(result);
    }   


    public String getter(){
        return result;
    }
}
class Solution {
    public String reverseParentheses(String s) {
        BusinessLogic bL=new BusinessLogic();
        bL.logic(s);
        return bL.getter();
    }
}

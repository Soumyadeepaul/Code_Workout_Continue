//https://leetcode.com/problems/longest-valid-parentheses/description/?envType=daily-question&envId=2026-10-03


interface Symbol{
    char getter();
}
interface Open extends Symbol{}
interface Close extends Symbol{}

class FirstOpen implements Open{
    @Override
    public char getter(){
        return '(';
    }
}
class SecondOpen implements Open{
    @Override
    public char getter(){
        return '{';
    }
}
class ThirdOpen implements Open{
    @Override
    public char getter(){
        return '[';
    }
}

class FirstClose implements Close{
    @Override
    public char getter(){
        return ')';
    }
}
class SecondClose implements Close{
    @Override
    public char getter(){
        return '}';
    }
}
class ThirdClose implements Close{
    @Override
    public char getter(){
        return ']';
    }
}


class BusinessLogic{
    private int result=0;
    Open firstOpen;
    Close firstClose;
    BusinessLogic(){
        this.firstOpen = new FirstOpen();
        this.firstClose = new FirstClose();
    }
    private void helper(String s, Symbol a, int start, int end){
        int open=0;
        int close=0;
        for(int i=start;;){
            if(s.charAt(i)==a.getter()) open++;
            else close++;

            if(open==close){
                result=Math.max(result,open*2);
            }
            else if(close>open){
                open=0;
                close=0;
            }
            if(i==end) break;
            if(start<end) i++;
            else i--;
            
        }
        if(open>close && a!=this.firstClose){
            this.helper(s,this.firstClose, s.length()-1, 0);
        }
    }

    public void bl(String s){
        if(s.length()!=0) this.helper(s,this.firstOpen, 0, s.length()-1);
    }

    public int getter(){
        return result;
    }



}


class Solution {
    public int longestValidParentheses(String s) {
        BusinessLogic bl=new BusinessLogic();
        bl.bl(s);
        return bl.getter();
    }
}

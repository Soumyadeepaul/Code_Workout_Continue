//https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/?envType=daily-question&envId=2026-09-26


class MemoryCreator{
    private HashMap<String,String> mp = new HashMap<>();
    MemoryCreator(){}
    public String getter(String get){
        if(mp.containsKey(get)){
            return mp.get(get);
        }
        return "?";
    } 
    public void setter(List<List<String>> knowledge){
        int l=knowledge.size();
        for(int i=0;i<l;i++){
            mp.put(knowledge.get(i).get(0), knowledge.get(i).get(1));
        }
    }
}


class BusinessLogic{
    private MemoryCreator memoryCreator;
    private String result="";
    BusinessLogic(MemoryCreator mc){
        this.memoryCreator=mc;
    }
    public void mapping(String s){

        String temp="";
        String result="";
        boolean flag=false;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                flag=true;
            }
            else if(s.charAt(i)==')'){
                flag=false;
                this.result+=memoryCreator.getter(temp);
                temp="";
            }
            else if(flag==true){
                temp+=s.charAt(i);
            }
            else if(flag==false){
                this.result+=s.charAt(i);

            }
        }


    }
    public void assignKnowledge(List<List<String>> knowledge){
        memoryCreator.setter(knowledge);
    }
    public String getter(){
        return this.result;
    }
}

class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        MemoryCreator mc= new MemoryCreator();
        BusinessLogic bL= new BusinessLogic(mc);

        bL.assignKnowledge(knowledge);
        bL.mapping(s);

        return bL.getter();
    }
}

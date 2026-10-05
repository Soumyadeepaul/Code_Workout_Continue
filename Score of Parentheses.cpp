//https://leetcode.com/problems/score-of-parentheses/description/?envType=daily-question&envId=2026-10-05


class Solution {
public:
    int scoreOfParentheses(string s) {
        //-1 = (
        stack<int> st;
        for(char ch:s){
            if(ch=='(') st.push(-1);
            else{
                int current=0;
                while(st.top()!=-1){
                    current+=st.top();
                    st.pop();
                }
                st.pop();
                if(current==0) st.push(1);
                else st.push(current*2);
            }
        }
        int current=0;
        while(!st.empty()){
            current+=st.top();
            st.pop();
        }
        return current;
    }
};

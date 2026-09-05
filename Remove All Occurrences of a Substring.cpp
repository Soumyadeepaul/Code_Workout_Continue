//https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/


class Solution {
public:
    bool checker(stack<char> st, string &part){
        int idx=0;
        int l=part.size();
        bool found=1;
        while(!st.empty()){
            if(st.top()==part[idx]){
                idx++;
                st.pop();
            }
            else{
                found=0;
                break;
            }
            if(idx==l) break;
        }
        if(idx!=l) return 0;
        return found;
    }
    void remover(stack<char>& st, int l){
        while(l!=0){
            st.pop();
            l--;
        }
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        reverse(part.begin(),part.end());
        int l=part.size();

        for(char ch:s){
            st.push(ch);
            while(checker(st,part)){
                remover(st,l);
            }
        }

        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

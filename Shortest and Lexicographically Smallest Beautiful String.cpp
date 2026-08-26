//https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/?envType=daily-question&envId=2026-08-26


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0, l=s.size();
        
        string result="";
        int count=0;
        for(int j=0;j<l;j++){
            if(s[j]=='1'){
                count++;

                if(count==k){
                    while(s[i]=='0') i++;
                    int take=j+1-i;
                    string temp=s.substr(i,take);
                    if(result=="" || result.size()>temp.size())result=temp;
                    else if(result.size()==temp.size()) result=min(result,temp);
                    i++;
                    count--;
                    while(i<=j && s[i]!='1') i++;
                }
            }
        }
        return result;
    }
};

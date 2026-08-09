//https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/


class Solution {
public:
    pair<bool,int> palin(int i,int j, string s, int k, int prevEnd){

        if(i==-1 || j>=s.size()){
            return {false,i};
        }
        while(i>prevEnd && j<s.size()){
            if(s[i]==s[j]){
                if(j-i+1>=k)return {true,j};
                i--;
                j++;
            }
            else{
                break;
            }
        }

        return {false,i};
    }
    int maxPalindromes(string s, int k) {
        if(k==1) return s.size();
        int count=0;
        int prevEnd=-1;
        for(int i=0;i<s.size();i++){
            if(i<=prevEnd) continue;
            auto get=palin(i-1,i+1,s,k,prevEnd);
            if(get.first){
                count++;
                
                prevEnd=get.second;
            }
            else{
                if(i+1<s.size() && s[i]==s[i+1]){
                    if(k==2){
                        prevEnd=i+1;
                        count++;
                    }
                    else{
                        auto get=palin(i-1,i+2,s,k,prevEnd);
                        if(get.first){
                            count++;
                            prevEnd=get.second;
                        }
                    }
                }
            }
        }
        return count;
    }
};

//https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/?envType=daily-question&envId=2026-07-28


class Solution {
public:
    string smallestPalindrome(string s) {
        int l=s.size();
        string result=string(l,'0');
        map<char,int> freq;
        queue<char> track;
        for(auto c:s) {
            freq[c]++;
        }
        int idx=0;
        char oddChar=NULL;
        for(auto p:freq){
            char c=p.first;
            int v=p.second;
            bool odd=false;
            if(v&1){
                v-=1;
                odd=true;
            }
            int place=v/2;
            while(place!=0){
                place--;
                result[idx]=c;
                result[l-1-idx]=c;
                idx++;
            }
            if(odd){
                oddChar=c;
            }
        }
        if(oddChar) result[idx]=oddChar;
        return result;
    }
};

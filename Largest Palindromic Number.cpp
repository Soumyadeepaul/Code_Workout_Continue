//https://leetcode.com/problems/largest-palindromic-number/description/


class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<char,int> freq;

        for(char ch:num) freq[ch]++;
        bool initial=0;
        string result="";
        //create 1st half
        unordered_set<char> store;
        for(int i='9';i>='0';i--){
            int temp=freq[i]/2;
            freq[i]-=temp;
            if(freq[i]==temp+1) store.insert(i);
            if(temp!=0 && initial==0 && i!='0') initial=1;
            else if(initial==0 && i=='0') continue;
            result+=string(temp,i);
            
            

        }
        string temp=result;
        for(int i='9';i>='0';i--){
            if(store.count(i)){
                result+=i;
                break;
            }
        }
        
        reverse(temp.begin(),temp.end());
        result=result+temp;
        if(result=="") return "0";
        return result;

    }
};

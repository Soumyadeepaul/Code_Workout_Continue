//https://leetcode.com/problems/repeated-string-match/description/



class Solution {
public:
    unordered_set<string> store;
    int idx=0;
    int helper(string a, string b, int l1, int l2){
        int count=1;
        string a1=a;
        int l=l1;
        while(l1<=2*(l2+l)){
            while(idx+l2<=l1){
                string temp(a.begin()+idx,a.begin()+idx+l2);
                store.insert(temp);
                idx++;
                if(store.find(b)!=store.end()) return count;
            }
            a+=a1;
            l1+=l;
            count++;
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        int l1=a.size(), l2=b.size();
        return helper(a,b,l1,l2);
    }
};

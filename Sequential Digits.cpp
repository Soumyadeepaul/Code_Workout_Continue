//https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2026-07-13


class Solution {
public:
    vector<int> result;
    int prev=0;
    void helper(int &low, int &high, int idx, string store){
        if(idx==store.size()){
            int s=stoi(store);
            if(s>=low && s<=high && s>prev){
                result.push_back(s);
                prev=s;
            }
            return;
        }
        if(idx!=0 && store[idx-1]!='0'){
            store[idx]=store[idx-1]+1;
            helper(low,high,idx+1,store);
            return;
        }
        for(int i=1;i<10;i++){
            store[idx]=i+'0';
            helper(low,high,idx+1,store);
        }

    }
    vector<int> sequentialDigits(int low, int high) {
        string l=to_string(low);
        string h=to_string(high);
        int lSize=l.size(), hSize=h.size();
        string store=string(hSize,'0');
        for(int idx=lSize;idx<=hSize;idx++){
            helper(low,high,hSize-idx,store);
        }
        return result;
    }
};

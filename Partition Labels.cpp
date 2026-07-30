//https://leetcode.com/problems/partition-labels/description/


class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> freq;
        for(auto c:s) freq[c]++;
        int i=-1,j=0,l=s.size();
        unordered_map<char,int> tracker;
        vector<int> result;
        while(j<l){
            tracker[s[j]]++;
            freq[s[j]]--;
            bool found=true;
            for(auto p:tracker){
                if(freq[p.first]!=0){ //present in future
                    found=false;
                    break;
                }
            }
            if (found){
                result.push_back(j-i);
                i=j;
                tracker.clear();
            }
            j++;
        }
        return result;
    }
};

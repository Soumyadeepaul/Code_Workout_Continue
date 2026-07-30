//https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/?envType=daily-question&envId=2026-07-30


class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mpp;
        for(auto w:word) mpp[w]++;
        priority_queue<vector<int>> pq;

        for(auto m:mpp){
            pq.push({m.second,m.first});
        }
        int count=0;
        int idx=1;
        int num=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            count+=(idx*top[0]);
            num++;
            if(num==8){
                idx++;
                num=0;
            }
        }
        return count;
    }
};

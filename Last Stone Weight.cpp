//https://leetcode.com/problems/last-stone-weight/description/?envType=problem-list-v2&envId=dsa-sequence-valley-heap


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(!pq.empty()){
            if(pq.size()==1) return pq.top();
            int l=pq.top();
            pq.pop();
            int r=pq.top();
            pq.pop();
            if(l==r) continue;
            else pq.push(l-r);
        }
        return 0;
    }
};
